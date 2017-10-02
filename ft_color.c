/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_color.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmouline <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/14 16:37:24 by cmouline          #+#    #+#             */
/*   Updated: 2015/06/14 16:37:25 by cmouline         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "npuzzle.h"

static void getrgb(int color, t_col *c)
{
	color_content(color, &(c->r), &(c->g), &(c->b));
}

static void	ft_init_pair(t_env *e)
{
	t_col	white;
	t_col	dark_blue;
	t_col	c;
	int		i;

	i = 0;
	getrgb(COLOR_WHITE, &white);
	getrgb(COLOR_BLUE, &dark_blue);
	while (i < e->size * e->size)
	{
		c.r = white.r + i * (dark_blue.r - white.r) / (e->size * e->size);
		c.g = white.g + i * (dark_blue.g - white.g) / (e->size * e->size);
		c.b = white.b + i * (dark_blue.b - white.b) / (e->size * e->size);
		init_color(196 + i, c.r, c.g, c.b);
		if (i == e->size * e->size - 1)
			init_pair(196 + i, COLOR_WHITE, 196 + i);
		else
			init_pair(196 + i, COLOR_BLACK, 196 + i);
		i++;
	}
	init_pair(1, COLOR_BLACK, 15);
}

void		ft_init_color(t_env *e)
{
	if (has_colors() == FALSE)
	{
		endwin();
		ft_error("Colors not supported\n");
	}
	start_color();
	ft_init_pair(e);
}
