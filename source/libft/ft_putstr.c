/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vomelchu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/29 13:03:29 by vomelchu          #+#    #+#             */
/*   Updated: 2018/04/04 16:47:35 by vomelchu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putstr(char const *s)
{
	int q;

	q = 0;
	if (s)
	{
		while (s[q] != '\0')
		{
			ft_putchar(s[q]);
			q++;
		}
	}
}
