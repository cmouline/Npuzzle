/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecouderc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/27 15:10:00 by ecouderc          #+#    #+#             */
/*   Updated: 2015/04/28 19:57:46 by cmouline         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "npuzzle.h"

int			ft_check_goal(t_env *e, int **tab)
{
	int		i;

	i = 0;
	while (i < e->size * e->size)
	{
		if (i != tab[e->goal[i].i][e->goal[i].j])
			return (0);
		i++;
	}
	return (1);
}
