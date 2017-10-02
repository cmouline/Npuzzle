/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_add.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecouderc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/24 17:56:51 by ecouderc          #+#    #+#             */
/*   Updated: 2015/04/25 17:32:56 by ecouderc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "npuzzle.h"

void	ft_add(t_set **set, t_set *elem)
{
	elem->state->openset = elem;
	elem->next = *set;
	if (*set != 0)
		(*set)->prev = elem;
	*set = elem;
}

void	ft_reposition(t_set **set, t_set *elem, t_set **old)
{
	if (elem->prev == 0)
		*old = elem->next;
	else
		elem->prev->next = elem->next;
	if (elem->next != 0)
		elem->next->prev = elem->prev;
	elem->next = 0;
	elem->prev = 0;
	ft_add(set, elem);
}
