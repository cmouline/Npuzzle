/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_state.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecouderc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/27 17:40:01 by ecouderc          #+#    #+#             */
/*   Updated: 2015/04/25 17:24:24 by ecouderc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "npuzzle.h"

t_state		*ft_state_cpy(t_env *e, t_state *state)
{
	t_state	*tmp;

	if (!(tmp = (t_state *)malloc(sizeof(t_state))))
		exit(1);
	tmp->tab = ft_tab_cpy(e, state->tab);
	tmp->id = state->id;
	tmp->start.i = state->start.i;
	tmp->start.j = state->start.j;
	tmp->score_g = state->score_g;
	tmp->score_f = state->score_f;
	tmp->open = state->open;
	tmp->closed = state->closed;
	tmp->came_from = state->came_from;
	tmp->neighbor[0] = 0;
	tmp->neighbor[1] = 0;
	tmp->neighbor[2] = 0;
	tmp->neighbor[3] = 0;
	tmp->openset = 0;
	return (tmp);
}

void		ft_state_free(t_env *e, t_state *state)
{
	ft_tab_free(e, state->tab);
	free(state);
}

t_set		*ft_state_comp(t_env *e, t_set *hist, t_state *state)
{
	t_set	*set;

	set = hist;
	while (set)
	{
		if (ft_tab_comp(e, state->tab, set->state->tab) == 1)
			return (set);
		set = set->next;
	}
	return (0);
}

uint32_t	ft_state_id(t_env *e, t_state *state)
{
	char	data[e->size * e->size];
	size_t	k;
	int		i;
	int		j;

	k = 0;
	i = 0;
	while (i < e->size)
	{
		j = 0;
		while (j < e->size)
		{
			data[k] = (const char)(state->tab[i][j]);
			k++;
			j++;
		}
		i++;
	}
	return (hash(data, e->size * e->size) % HASH_NUM);
}
