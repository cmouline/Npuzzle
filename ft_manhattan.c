/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_manhattan.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecouderc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/24 16:00:38 by ecouderc          #+#    #+#             */
/*   Updated: 2015/04/24 21:07:38 by ecouderc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "npuzzle.h"

static int	ft_cost(t_env *e, t_state *state, int i, int j)
{
	int		cost;
	int		cost_i;
	int		cost_j;

	cost_i = e->goal[state->tab[i][j]].i - i;
	cost_i = (cost_i < 0) ? -cost_i : cost_i;
	cost_j = e->goal[state->tab[i][j]].j - j;
	cost_j = (cost_j < 0) ? -cost_j : cost_j;
	cost = cost_i + cost_j;
	return (cost);
}

int			ft_manhattan(t_env *e, t_state *state)
{
	int		i;
	int		j;
	int		ret;

	ret = 0;
	i = 0;
	while (i < e->size)
	{
		j = 0;
		while (j < e->size)
		{
			ret += ft_cost(e, state, i, j);
			j++;
		}
		i++;
	}
	return (ret);
}
