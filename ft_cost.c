/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cost.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecouderc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/24 15:48:47 by ecouderc          #+#    #+#             */
/*   Updated: 2015/04/24 21:06:48 by ecouderc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "npuzzle.h"

static void	ft_cost_tile(t_env *e, int i, int j)
{
	int		i_goal;
	int		j_goal;

	i_goal = e->tab[i][j] / e->size;
	j_goal = e->tab[i][j] % e->size;
	e->tab[i][j].cost = (ABS(i_goal - i)) + (ABS(j_goal - j));
}

void		ft_cost(t_env *e)
{
	int		i;
	int		j;

	i = 0;
	while (i < e->size)
	{
		j = 0;
		while (j < e->size)
		{
			ft_cost_tile(e, i, j);
			j++;
		}
		i++;
	}
}
