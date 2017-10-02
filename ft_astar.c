/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_astar.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecouderc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/24 16:29:13 by ecouderc          #+#    #+#             */
/*   Updated: 2015/07/04 20:17:07 by ecouderc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "npuzzle.h"

static t_state	*ft_new_neighbor(t_env *e, int i, int j)
{
	t_set		*set;
	t_state		*neighbor;

	neighbor = ft_state_cpy(e, e->current);
	neighbor->tab[neighbor->start.i][neighbor->start.j] = neighbor->tab[i][j];
	neighbor->tab[i][j] = 0;
	neighbor->start.i = i;
	neighbor->start.j = j;
	neighbor->open = 0;
	neighbor->closed = 0;
	neighbor->id = ft_state_id(e, neighbor);
	set = ft_state_comp(e, e->hist[neighbor->id], neighbor);
	if (set == 0)
		ft_add(&(e->hist[ft_state_id(e, neighbor)]), ft_elem(neighbor));
	else
	{
		ft_state_free(e, neighbor);
		neighbor = set->state;
	}
	return (neighbor);
}

static void		ft_reevaluate(t_env *e, int k, t_state *neighbor)
{
	int			old_score_f;

	old_score_f = neighbor->score_f;
	e->current->neighbor[k] = neighbor;
	neighbor->came_from = (k + 2) % 4;
	neighbor->neighbor[neighbor->came_from] = e->current;
	neighbor->score_g = e->current->score_g + 1;
	neighbor->score_f = neighbor->score_g
		+ heuristic_cost_estimate(e, neighbor);
	if (neighbor->closed == 1)
	{
		neighbor->closed = 0;
		neighbor->open = 1;
		ft_add(&(e->openset[neighbor->score_f]), ft_elem(neighbor));
		e->open_nb++;
		e->open_max = (e->open_nb > e->open_max) ? e->open_nb : e->open_max;
	}
	else
	{
		ft_reposition(&(e->openset[neighbor->score_f]), neighbor->openset,
				&(e->openset[old_score_f]));
	}
}

static void		ft_neighbor(t_env *e, int i, int j, int k)
{
	t_state		*neighbor;

	neighbor = e->current->neighbor[k];
	if (neighbor == 0)
		neighbor = ft_new_neighbor(e, i, j);
	if (neighbor->open == 0 && neighbor->closed == 0)
	{
		e->current->neighbor[k] = neighbor;
		neighbor->came_from = (k + 2) % 4;
		neighbor->neighbor[neighbor->came_from] = e->current;
		neighbor->score_g = e->current->score_g + 1;
		neighbor->score_f = neighbor->score_g
			+ heuristic_cost_estimate(e, neighbor);
		neighbor->open = 1;
		ft_add(&(e->openset[neighbor->score_f]), ft_elem(neighbor));
		e->open_nb++;
		e->open_max = (e->open_nb > e->open_max) ? e->open_nb : e->open_max;
	}
	else
	{
		if (neighbor->score_g > e->current->score_g + 1)
			ft_reevaluate(e, k, neighbor);
	}
}

static int		ft_astar(t_env *e)
{
	t_set		*currentset;

	while (check_empty(e) == 0)
	{
		currentset = ft_lowest_score(e);
		e->open_select++;
		e->current = currentset->state;
		if (e->current->score_g == e->current->score_f)
			return (reconstruct_path(e));
		e->current->open = 0;
		ft_remove(&(e->openset[e->current->score_f]), currentset);
		e->open_nb--;
		e->current->closed = 1;
		if (e->current->start.i > 0)
			ft_neighbor(e, e->current->start.i - 1, e->current->start.j, 0);
		if (e->current->start.j > 0)
			ft_neighbor(e, e->current->start.i, e->current->start.j - 1, 1);
		if (e->current->start.i < e->size - 1)
			ft_neighbor(e, e->current->start.i + 1, e->current->start.j, 2);
		if (e->current->start.j < e->size - 1)
			ft_neighbor(e, e->current->start.i, e->current->start.j + 1, 3);
	}
	ft_error("unsolvable");
	return (-1);
}

int				ft_astar_init(t_env *e)
{
	t_state		*tmp;

	ft_goal(e);
	ft_solvability(e);
	if (e->solv == 0)
		ft_error("This puzzle is unsolvable");
	e->state_0.came_from = -1;
	e->state_0.id = ft_state_id(e, &(e->state_0));
	e->state_0.score_g = 0;
	e->state_0.score_f = e->state_0.score_g
		+ heuristic_cost_estimate(e, &(e->state_0));
	tmp = ft_state_cpy(e, &(e->state_0));
	ft_add(&(e->hist[tmp->id]), ft_elem(tmp));
	e->final_score = tmp->score_f;
	ft_add(&(e->openset[tmp->score_f]), ft_elem(tmp));
	e->open_nb++;
	e->open_max = (e->open_nb > e->open_max) ? e->open_nb : e->open_max;
	return (ft_astar(e));
}
