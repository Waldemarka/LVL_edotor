/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   doom_nukem.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vomelchu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/20 14:15:45 by vomelchu          #+#    #+#             */
/*   Updated: 2018/10/20 14:19:55 by vomelchu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOOM_NUKEM_H
# define DOOM_NUKEM_H

# include <unistd.h>
# include "../source/libft/includes/libft.h"
# include <SDL.h>
# include <SDL_image.h>
# include <SDL_ttf.h>
# include <SDL_mixer.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdio.h>
# include <math.h>

#define WIDTH 720
#define HEIGHT 720

typedef struct  s_vector
{
        double x;
        double y;
}               vector;

typedef struct  s_sector
{
                int x0;
                int y0;
                struct s_sector *next;
               // struct s_sector *previous; 
}               t_sector;

typedef struct  s_data
{
    SDL_Window      *win;
    SDL_Renderer    *ren;
    SDL_Texture     *screen;
    SDL_Texture     *dot;

    char            *name;
    int             buf[HEIGHT][WIDTH];
    int             for_exit;
    int             fd;

    int             x0;
    int             y0;
    int             x1;
    int             y1;
    int             x0_line;
    int             y0_line;
    int             x1_line;
    int             y1_line;
    int             deltax;
    int             deltay;
    int             x_step;
    int             y_step;
    int             color;
    int             step_for_x;
    int             step_for_y;
    int             for_realloc;
    int             current_sector;
    int             check_click;

    int             max_canv_x;
    int             max_canv_y;
    int             start_coord_x;
    int             start_coord_y;

    float           x_canv;
    float           y_canv;

    int             iter;

    int             change_position;
    int             chang;

    t_sector        *sectors;
    t_sector        *tmp;
    t_sector        *change_coord;
    vector          p1;
    vector          p2;
    vector          p3;
    vector          p4;
}                   t_data;

void                ft_error(char *str);
void                key_event(t_data *data);
void                key_helper(t_data *data, SDL_Event  event);
void                bresenham_line(t_data *data);
void                mouse_line(t_data *data);
void                list_realloc(t_data *data);
void                list_malloc(t_sector **list, int size);
void                fill_next(t_data *data, int x, int y);
void                draw_lines(t_data *data);
void                draw_grid(t_data *data);
void                dots_to_bres(t_data *data);
void                coord_canvas(t_data *data, int x, int y);
void                coord_displ(t_data *data, int x, int y);
void                limit_coord(t_data *data, int x, int y);
void                writting(t_data *data);
int                 near_round(int q);
void                near_lines(t_data *data);
int                 bef_crossing(t_data *data);
int                 len_list(t_sector *sectors);
int                 max(int x, int y);
int                 min(int x, int y);
int                 normal_vec(t_data *data);
int                 first_vert(t_data *data);
int                 second_vert(t_data *data);

int                 touch_dots(t_data *data);

SDL_Surface         *load_image(char *path);
unsigned int        get_pixel_int(SDL_Surface *surface, int x, int y);

#endif