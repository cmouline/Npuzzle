/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmouline <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/14 16:43:01 by cmouline          #+#    #+#             */
/*   Updated: 2015/07/04 21:39:05 by ecouderc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "npuzzle.h"

void		ft_stop_ncurses(int sig)
{
	timeout(0);
	clear();
	refresh();
	endwin();
	if (sig == SIGINT || sig == SIGQUIT)
		exit(EXIT_FAILURE);
}

int			ft_init_ncurses(t_env *e)
{
	if (!(setlocale(LC_ALL, "")))
		ft_error("fail to change the locale");
	signal(SIGINT, ft_stop_ncurses);
	signal(SIGQUIT, ft_stop_ncurses);
	if (!(e->win = initscr()))
		ft_error("fail to initiate ncurse");
	timeout(-1);
	curs_set(0);
	noecho();
	return (0);
}
