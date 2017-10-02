/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecouderc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/27 23:11:56 by ecouderc          #+#    #+#             */
/*   Updated: 2015/04/26 17:48:18 by ecouderc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "npuzzle.h"

unsigned int	ft_count(t_set *set)
{
	t_set			*tmp;
	unsigned int	count;

	count = 0;
	tmp = set;
	while (tmp)
	{
		count++;
		tmp = tmp->next;
	}
	return (count);
}

unsigned int	ft_count_hist(t_set **hist)
{
	int				i;
	unsigned int	count;

	count = 0;
	i = 0;
	while (i < HASH_NUM)
	{
		count += ft_count(hist[i]);
		i++;
	}
	return (count);
}

unsigned int	ft_max_hist(t_set **hist)
{
	unsigned int	max;
	unsigned int	count;
	int				i;

	max = 0;
	i = 0;
	while (i < HASH_NUM)
	{
		count = 0;
		count += ft_count(hist[i]);
		if (count > max)
			max = count;
		i++;
	}
	return (max);
}
