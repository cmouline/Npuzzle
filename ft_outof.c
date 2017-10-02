/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_outof.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecouderc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/28 15:55:24 by ecouderc          #+#    #+#             */
/*   Updated: 2015/04/28 16:01:38 by ecouderc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "npuzzle.h"

static int	ft_cost(t_env *e, t_state *state, int i, int j)
{
	int		cost;

	cost = 0;
	if (e->goal[state->tab[i][j]].i != i)
		cost++;
	if (e->goal[state->tab[i][j]].j != j)
		cost++;
	return (cost);
}

int			ft_outof(t_env *e, t_state *state)
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
