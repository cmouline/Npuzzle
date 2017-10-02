/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_grid.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmouline <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/25 19:51:05 by cmouline          #+#    #+#             */
/*   Updated: 2015/07/04 19:50:55 by ecouderc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "npuzzle.h"

static void	ft_print_square(t_env *e, int **tab, int i, int j)
{
	int k;
	int l;

	l = i * 3;
	while (l < (i * 3) + 3)
	{
		k = j * 8;
		while (k < (j * 8) + 8)
		{
			mvprintw(l + 10, (e->win_w / 3) - (e->size * 7) + k, PAD_CHAR);
			k++;
		}
		l++;
	}
	mvprintw(10 + (l - 2), (e->win_w / 3) - (e->size * 7) + (k - 5),
			"%d", tab[i][j]);
}

void		ft_print_curr_grid(t_env *e, int **tab)
{
	int	i;
	int	j;
	int id_color;

	i = 0;
	while (i < e->size)
	{
		j = 0;
		while (j < e->size)
		{
			if (tab[i][j] == 0)
				id_color = 196 + (e->size * e->size - 1);
			else
				id_color = 196 + (tab[i][j] - 1);
			attron(COLOR_PAIR(id_color));
			ft_print_square(e, tab, i, j);
			attroff(COLOR_PAIR(id_color));
			j++;
		}
		i++;
	}
}
