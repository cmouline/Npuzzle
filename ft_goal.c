/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_goal.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecouderc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/27 14:47:35 by ecouderc          #+#    #+#             */
/*   Updated: 2015/04/26 15:38:27 by ecouderc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "npuzzle.h"

static void	ft_border2(t_env *e, int count, int n, int size)
{
	int		i;
	int		j;

	i = n + size - 1;
	j = n + size - 2;
	while (j >= n + 0)
	{
		e->goal[count % (e->size * e->size)].i = i;
		e->goal[count % (e->size * e->size)].j = j;
		count++;
		j--;
	}
	i = n + size - 2;
	j = n;
	while (i >= n + 1)
	{
		e->goal[count % (e->size * e->size)].i = i;
		e->goal[count % (e->size * e->size)].j = j;
		count++;
		i--;
	}
}

static void	ft_border1(t_env *e, int count, int n, int size)
{
	int		i;
	int		j;

	i = n;
	j = n;
	while (j < n + size)
	{
		e->goal[count % (e->size * e->size)].i = i;
		e->goal[count % (e->size * e->size)].j = j;
		count++;
		j++;
	}
	i = n + 1;
	j = n + size - 1;
	while (i < n + size)
	{
		e->goal[count % (e->size * e->size)].i = i;
		e->goal[count % (e->size * e->size)].j = j;
		count++;
		i++;
	}
	ft_border2(e, count, n, size);
}

void		ft_goal(t_env *e)
{
	int		count;
	int		size;
	int		n;

	n = 0;
	count = 1;
	size = e->size;
	if (!(e->goal = (t_node *)malloc(sizeof(t_node) * (e->size * e->size))))
		exit(1);
	while (count <= e->size * e->size && size > 0)
	{
		ft_border1(e, count, n, size);
		count += size * 2 + (size - 2) * 2;
		size -= 2;
		n++;
	}
}
