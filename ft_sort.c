/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecouderc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/24 21:59:46 by ecouderc          #+#    #+#             */
/*   Updated: 2015/04/24 22:40:03 by ecouderc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "npuzzle.h"

static void		ft_swap(t_set *s1, t_set *s2, t_set **begin)
{
	if (s1->prev == 0)
		*begin = s2;
	s2->prev = s1->prev;
	s1->next = s2->next;
	s2->next = s1;
	s1->prev = s2;
}

void			ft_sort(t_set **set)
{
	int			count;
	t_set		*tmp;

	count = 1;
	while (count != 0)
	{
		tmp = *set;
		count = 0;
		while (tmp && tmp->next)
		{
			if (tmp->state->score_f > tmp->next->state->score_f)
			{
				ft_swap(tmp, tmp->next, set);
				count++;
			}
			else
				tmp = tmp->next;
		}
	}
}
