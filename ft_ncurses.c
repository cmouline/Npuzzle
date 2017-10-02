/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ncurses.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmouline <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/08 11:25:34 by cmouline          #+#    #+#             */
/*   Updated: 2015/07/04 22:13:40 by ecouderc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "npuzzle.h"

static	int		ft_getmax_moves(t_set *path)
{
	while (path->next != NULL)
		path = path->next;
	return (path->prev->nb);
}

static	void	ft_print(t_env *e, t_set *path, int max_moves)
{
	ft_print_text(e, path, max_moves);
	ft_print_curr_grid(e, path->state->tab);
}

static	void	ft_loop(t_env *e, t_set *path, int max_moves)
{
	int		key;
	int		h;
	int		w;

	keypad(e->win, true);
	while (42)
	{
		getmaxyx(e->win, h, w);
		if (e->win_h != h || e->win_w != w)
		{
			clear();
			refresh();
			getmaxyx(e->win, e->win_h, e->win_w);
		}
		ft_print(e, path, max_moves);
		key = getch();
		if (key == 27)
			break ;
		else if (key == KEY_UP && path->prev != NULL)
			path = path->prev;
		else if (key == KEY_DOWN && path->next != NULL)
			path = path->next;
	}
}

void			ft_ncurses(t_env *e)
{
	int		max_moves;
	t_set	*path;

	path = e->path;
	max_moves = ft_getmax_moves(path);
	ft_init_ncurses(e);
	ft_init_color(e);
	ft_loop(e, path, max_moves);
	ft_stop_ncurses(0);
}
