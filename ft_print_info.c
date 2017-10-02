/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_info.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmouline <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/14 16:47:19 by cmouline          #+#    #+#             */
/*   Updated: 2015/07/04 19:48:32 by ecouderc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "npuzzle.h"

static void	ft_print_score(t_env *e, int moves)
{
	mvprintw(12, e->win_w / 2, "F score : %d", e->final_score);
	mvprintw(13, e->win_w / 2, "Total number of states ever selected");
	mvprintw(14, e->win_w / 2, "in the 'opened' set : %d", e->open_select);
	mvprintw(15, e->win_w / 2, "Maximum number of states ever represented");
	mvprintw(16, e->win_w / 2, "in memory at the same time : %d", e->open_max);
	mvprintw(17, e->win_w / 2, "Number of moves : %d", moves);
	mvprintw(19, e->win_w / 2, "Next moves :");
}

static void ft_print_finish(t_env *e, int i)
{
	mvprintw(20 + i, e->win_w / 2, "           ");
	mvprintw(20 + i + 1, e->win_w / 2, "Finish !   ");
	while (i < 10)
	{
		mvprintw(20 + i + 2, e->win_w / 2, "           ");
		i++;
	}
}

static void	ft_print_path(t_env *e, t_set *path)
{
	int	i;

	i = 0;
	while (i < 10)
	{
		if (path->next)
		{
			if (path->next->state->came_from == 0)
				mvprintw(20 + i, e->win_w / 2, "%d. Down    ", path->nb);
			if (path->next->state->came_from == 1)
				mvprintw(20 + i, e->win_w / 2, "%d. Right   ", path->nb);
			if (path->next->state->came_from == 2)
				mvprintw(20 + i, e->win_w / 2, "%d. Up      ", path->nb);
			if (path->next->state->came_from == 3)
				mvprintw(20 + i, e->win_w / 2, "%d. Left    ", path->nb);
			mvprintw(20 + 10, e->win_w / 2, "           ");
			path = path->next;
		}
		else
		{
			ft_print_finish(e, i);
			break ;
		}
		i++;
	}
}

static void	ft_print_heuristic(t_env *e)
{
	char	*heur;

	heur = ft_memalloc(sizeof(char) * 100);
	heur = strcpy(heur, "Heuristique : ");
	if (e->man == 1)
		heur = ft_strcat(heur, "- Manhattan ");
	if (e->ham == 1)
		heur = ft_strcat(heur, "- Hamming ");
	if (e->lin == 1)
		heur = ft_strcat(heur, "- Linear ");
	if (e->oor == 1)
		heur = ft_strcat(heur, "- Out of Row and Column ");
	if (e->mxs == 1)
		heur = ft_strcat(heur, "- Maxswap ");
	mvprintw(8, e->win_w / 2 - ft_strlen(heur) / 2, heur);
	free(heur);
}

void		ft_print_text(t_env *e, t_set *path, int max_moves)
{
	mvprintw(1, (e->win_w - ft_strlen(ASCII_1) - ft_strlen(ASCII_10)) / 2,
			"%s%s", ASCII_1, ASCII_10);
	mvprintw(2, (e->win_w - ft_strlen(ASCII_2) - ft_strlen(ASCII_20)) / 2,
			"%s%s", ASCII_2, ASCII_20);
	mvprintw(3, (e->win_w - ft_strlen(ASCII_3) - ft_strlen(ASCII_30)) / 2,
			"%s%s", ASCII_3, ASCII_30);
	mvprintw(4, (e->win_w - ft_strlen(ASCII_4) - ft_strlen(ASCII_40)) / 2,
			"%s%s", ASCII_4, ASCII_40);
	mvprintw(5, (e->win_w - ft_strlen(ASCII_5) - ft_strlen(ASCII_50)) / 2,
			"%s%s", ASCII_5, ASCII_50);
	mvprintw(6, (e->win_w - ft_strlen(ASCII_6) - ft_strlen(ASCII_60)) / 2,
			"%s%s", ASCII_6, ASCII_60);
	ft_print_heuristic(e);
	ft_print_score(e, max_moves);
	ft_print_path(e, path);
	if (e->solv == 1)
		mvprintw(10, e->win_w / 2, "This puzzle is solvable.");
	else if (e->solv == 0)
		mvprintw(10, e->win_w / 2, "This puzzle is unsolvable.");
}
