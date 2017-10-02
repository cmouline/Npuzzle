/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hamming.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmouline <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/25 16:03:03 by cmouline          #+#    #+#             */
/*   Updated: 2015/04/24 21:07:11 by ecouderc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "npuzzle.h"

int		ft_hamming(t_env *e, t_state *state)
{
	int	count;
	int i;
	int j;

	i = 0;
	count = 0;
	while (i < e->size)
	{
		j = 0;
		while (j < e->size)
		{
			if (e->goal[state->tab[i][j]].i != i
				|| e->goal[state->tab[i][j]].j != j)
				count++;
			j++;
		}
		i++;
	}
	return (count);
}
