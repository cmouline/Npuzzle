/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_remove.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecouderc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/24 17:38:23 by ecouderc          #+#    #+#             */
/*   Updated: 2015/04/20 18:27:30 by ecouderc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "npuzzle.h"

void	ft_remove(t_set **set, t_set *elem)
{
	if (elem == 0)
		ft_error("we have a problem");
	if (elem->prev == 0)
		*set = elem->next;
	else
		elem->prev->next = elem->next;
	if (elem->next != 0)
		elem->next->prev = elem->prev;
	free(elem);
}
