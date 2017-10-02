/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_maxswap2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmouline <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/28 19:53:57 by cmouline          #+#    #+#             */
/*   Updated: 2015/04/28 19:53:58 by cmouline         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "npuzzle.h"

static void		ft_swap(t_node *n1, t_node *n2, int **tab)
{
	tab[n1->i][n1->j] = tab[n2->i][n2->j];
	tab[n2->i][n2->j] = 0;
	n1->i = n2->i;
	n1->j = n2->j;
}

static t_node	ft_misfits(t_env *e, int **tab)
{
	t_node	n;

	n.i = 0;
	while (n.i < e->size)
	{
		n.j = 0;
		while (n.j < e->size)
		{
			if ((e->goal[tab[n.i][n.j]].i != n.i
				|| e->goal[tab[n.i][n.j]].j != n.j)
				&& tab[n.i][n.j] != 0)
				return (n);
			n.j++;
		}
		n.i++;
	}
	ft_error("no misfits");
	return (n);
}

static t_node	ft_seek_pos(t_env *e, int **tab, int k)
{
	t_node	node;

	node.i = 0;
	while (node.i < e->size)
	{
		node.j = 0;
		while (node.j < e->size)
		{
			if (tab[node.i][node.j] == k)
				return (node);
			node.j++;
		}
		node.i++;
	}
	ft_error("not found");
	return (node);
}

static int		ft_seek_goal(t_env *e, t_node n)
{
	int k;

	k = 0;
	while (k < e->size * e->size)
	{
		if (e->goal[k].i == n.i && e->goal[k].j == n.j)
			return (k);
		k++;
	}
	ft_error("not found");
	return (-1);
}

int				ft_maxswap(t_env *e, t_state *state)
{
	t_node	n1;
	t_node	n2;
	int		cost;
	int		**tab;

	cost = 0;
	n1.i = state->start.i;
	n1.j = state->start.j;
	tab = ft_tab_cpy(e, state->tab);
	while (ft_check_goal(e, tab) == 0)
	{
		n2 = ft_seek_pos(e, tab, ft_seek_goal(e, n1));
		if (n2.i == e->goal[0].i && n2.j == e->goal[0].j)
			n2 = ft_misfits(e, tab);
		ft_swap(&n1, &n2, tab);
		cost++;
	}
	ft_tab_free(e, tab);
	return (cost);
}
