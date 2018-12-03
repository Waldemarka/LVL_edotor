/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   doom_nukem.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vomelchu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/20 14:13:01 by vomelchu          #+#    #+#             */
/*   Updated: 2018/11/26 18:02:27 by vomelchu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doom_nukem.h"

void    ft_error(char *str)
{
	ft_putstr(str);
	exit(0);
}

void    init_all(t_data *data)
{
	if (SDL_Init(SDL_INIT_EVERYTHING) < 0)
		ft_error("BAD INIT SDL2\n");
	if (!(data->win = SDL_CreateWindow("Doom_nukem", 400, 400, WIDTH,
					HEIGHT, SDL_WINDOW_SHOWN)))
		ft_error("BAD INIT SDL2\n");
	if (!(data->ren = SDL_CreateRenderer(data->win, -1, SDL_RENDERER_ACCELERATED
					| SDL_RENDERER_PRESENTVSYNC)))
		ft_error("BAD INIT SDL2\n");
	if (!(data->screen = SDL_CreateTexture(data->ren,
					SDL_PIXELFORMAT_ARGB8888, SDL_TEXTUREACCESS_TARGET, WIDTH, HEIGHT)))
		ft_error("BAD INIT SDL2\n");
	data->for_realloc = 1;
	data->current_sector = 0;
	data->sectors[0].next = NULL;
	data->check_click = 0;
	data->max_canv_x = 360;
	data->max_canv_y = 360;
	data->start_coord_x = 0;
	data->start_coord_y = 0;
	data->change_position = 0;
	data->chang = 0;
	data->tmp_count = 0;
	data->dot = load_image("dot.png");
}

void    game(t_data *data)
{
	while (data->for_exit != 1)
	{
		SDL_UpdateTexture(data->screen, NULL, data->buf, WIDTH << 2);
		SDL_RenderCopy(data->ren, data->screen, NULL, NULL);
		SDL_RenderPresent(data->ren);
		int i = -1;
		while (++i != HEIGHT)
		{
			int x = -1;
			while(++x != WIDTH)
			{
				data->buf[i][x] = 0;
			}
		}
		key_event(data);
		draw_grid(data);
		data->color = 0x15eb43;
		if (data->change_position == 0)
			mouse_line(data);
		else if (data->change_position == 1)
			change_position(data);
		if (data->check_click != 0)
		{
			bresenham_line(data);
			draw_lines(data);
		}
		else
			draw_lines(data);
		i = -1;
		while (++i != HEIGHT)
		{
			int x = -1;
			while(++x != WIDTH)
			{
				if (data->buf[i][x] == 0)
					data->buf[i][x] = 0x4f4b4b;
			}
		}
        //draw_icon(data);
	}
}

int     main(int argc, char **argv)
{
	t_data *data;

	if (argc == 2)
	{
		if (!(data = (t_data *)malloc(sizeof(t_data))))
			ft_error("BAD MALLOC FOR STRUCT\n");
		data->name = argv[1];
		data->fd = open(data->name, O_DIRECTORY);
		if (data->fd >= 0)
			ft_error("NOT DIRECTORY\n");
		list_malloc(&data->sectors, 1);
		data->sectors[0].next = NULL;
		init_all(data);
		game(data);
	}
	else
		ft_error("BAD NUM ARGC\n");
	return (0);
}