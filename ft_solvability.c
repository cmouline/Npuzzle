/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_solvability.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecouderc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/25 19:38:18 by ecouderc          #+#    #+#             */
/*   Updated: 2015/07/04 18:41:05 by ecouderc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "npuzzle.h"

static int	ft_inversion(t_env *e)
{
	int		inversions;
	int		line[e->size * e->size];
	int		i;
	int		j;

	i = 0;
	while (i < e->size * e->size)
	{
		line[i] = e->state_0.tab[e->goal[i].i][e->goal[i].j];
		i++;
	}
	inversions = 0;
	i = 0;
	while (i < e->size * e->size - 1)
	{
		j = i + 1;
		while (j < e->size * e->size)
		{
			if (line[i] > line[j])
				inversions++;
			j++;
		}
		i++;
	}
	return (inversions % 2);
}

void		ft_solvability(t_env *e)
{
	int		width;
	int		pos0;
	int		dep0;
	int		inversions;
	int		i;

	pos0 = 0;
	width = e->size % 2;
	i = 0;
	while (i < e->size * e->size)
	{
		if (e->goal[i].i == e->state_0.start.i
				&& e->goal[i].j == e->state_0.start.j)
		{
			pos0 = i;
			break ;
		}
		i++;
	}
	pos0 = (e->size * e->size - pos0 + 1) % 2;
	dep0 = (ABS(e->goal[0].i - e->state_0.start.i)
			+ ABS(e->goal[0].j - e->state_0.start.j)) % 2;
	inversions = ft_inversion(e);
	e->solv = ((width == 1 && ((dep0 == 1) == (inversions == 1)))
			|| (width == 0 && ((pos0 == 1) == (inversions == 0)))) ? 1 : 0;
}
