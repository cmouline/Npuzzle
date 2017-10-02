/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_pos.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecouderc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/25 20:06:21 by ecouderc          #+#    #+#             */
/*   Updated: 2015/07/04 20:18:36 by ecouderc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "npuzzle.h"

void		ft_print_pos(t_env *e)
{
	t_set	*path;

	path = e->path;
	while (path)
	{
		ft_putstr("path_rev: i = ");
		ft_putnbr(path->state->start.i);
		ft_putstr(", j = ");
		ft_putnbr(path->state->start.j);
		ft_putchar('\n');
		ft_putstr("g_score: ");
		ft_putnbr(path->state->score_g);
		ft_putchar('\n');
		ft_putstr("f_score: ");
		ft_putnbr(path->state->score_f);
		ft_putchar('\n');
		ft_print_grid(e, path->state->tab);
		path = path->next;
	}
}
