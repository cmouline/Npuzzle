/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_astar_0.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecouderc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/24 16:29:13 by ecouderc          #+#    #+#             */
/*   Updated: 2015/07/04 18:55:01 by ecouderc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "npuzzle.h"

int		check_empty(t_env *e)
{
	int			i;

	i = 0;
	while (i < HASH_NUM)
	{
		if (e->openset[i] != 0)
			return (0);
		i++;
	}
	return (1);
}

t_set	*ft_lowest_score(t_env *e)
{
	int			i;

	i = 0;
	while (i < HASH_NUM)
	{
		if (e->openset[i] != 0)
			return (e->openset[i]);
		i++;
	}
	ft_error("open set is empty");
	return (0);
}

int		reconstruct_path(t_env *e)
{
	t_state		*state;
	int			i;

	i = 1;
	e->path = 0;
	state = e->current;
	while (42)
	{
		ft_add(&(e->path), ft_elem(state));
		if (state->came_from == -1)
			break ;
		state = state->neighbor[state->came_from];
	}
	while (e->path->next != NULL)
	{
		e->path->nb = i;
		e->path = e->path->next;
		i++;
	}
	while (e->path->prev != NULL)
		e->path = e->path->prev;
	return (1);
}
