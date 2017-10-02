/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_elem.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecouderc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/25 18:18:32 by ecouderc          #+#    #+#             */
/*   Updated: 2015/03/27 18:48:18 by ecouderc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "npuzzle.h"

t_set		*ft_elem(t_state *state)
{
	t_set	*elem;

	if (!(elem = (t_set *)malloc(sizeof(t_set))))
		exit(1);
	elem->state = state;
	elem->next = 0;
	elem->prev = 0;
	return (elem);
}
