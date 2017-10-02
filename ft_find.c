/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecouderc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/25 18:42:49 by ecouderc          #+#    #+#             */
/*   Updated: 2015/04/25 17:27:52 by ecouderc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "npuzzle.h"

t_set		*ft_find(t_env *e, t_set *set, t_state *state)
{
	t_set		*tmp;

	tmp = set;
	while (tmp)
	{
		if (ft_tab_comp(e, tmp->state->tab, state->tab) == 1)
			return (tmp);
		tmp = tmp->next;
	}
	ft_error("state not found");
	return (0);
}
