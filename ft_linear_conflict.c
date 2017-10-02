/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_linear_conflict.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmouline <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/27 11:32:51 by cmouline          #+#    #+#             */
/*   Updated: 2015/04/27 11:32:52 by cmouline         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "npuzzle.h"

static int	ft_case2(t_env *e, t_state *state, int i, int j)
{
	int k;
	int cost;

	k = i + 1;
	cost = 0;
	while (k < e->size)
	{
		if (e->goal[state->tab[k][j]].j == j)
		{
			if (e->goal[state->tab[k][j]].i < e->goal[state->tab[i][j]].i)
				cost += 2;
		}
		k++;
	}
	return (cost);
}

static int	ft_case1(t_env *e, t_state *state, int i, int j)
{
	int k;
	int cost;

	k = j + 1;
	cost = 0;
	while (k < e->size)
	{
		if (e->goal[state->tab[i][k]].i == i)
		{
			if (e->goal[state->tab[i][k]].j < e->goal[state->tab[i][j]].j)
				cost += 2;
		}
		k++;
	}
	return (cost);
}

static int	ft_cost(t_env *e, t_state *state, int i, int j)
{
	int		cost;

	cost = 0;
	if (e->goal[state->tab[i][j]].i == i)
		cost = ft_case1(e, state, i, j);
	if (e->goal[state->tab[i][j]].j == j)
		cost += ft_case2(e, state, i, j);
	return (cost);
}

int			ft_linear(t_env *e, t_state *state)
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
