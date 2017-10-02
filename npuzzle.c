/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   npuzzle.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecouderc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/24 15:07:21 by ecouderc          #+#    #+#             */
/*   Updated: 2015/07/04 22:16:46 by ecouderc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "npuzzle.h"

static void	ft_get_heuristic(t_env *e, char *str)
{
	if (ft_strequ("-m", str) == 1)
		e->man = 1;
	else if (ft_strequ("-h", str) == 1)
		e->ham = 1;
	else if (ft_strequ("-l", str) == 1)
	{
		e->man = 1;
		e->lin = 1;
	}
	else if (ft_strequ("-o", str) == 1)
		e->oor = 1;
	else if (ft_strequ("-mx", str) == 1)
		e->mxs = 1;
	else if (ft_strequ("-help", str) == 1)
	{
		ft_putendl("Choose your heuristic :");
		ft_putendl("-m for Manhattan");
		ft_putendl("-h for Hamming");
		ft_putendl("-l for Linear Conflict");
		ft_putendl("-o for Out of Row and Column");
		ft_putendl("-mx for Maxswap");
		exit(0);
	}
	else
		ft_error("Choose a valid heuristic.\n-help to see options.");
}

static int	ft_options(t_env *e, int ac, char **av)
{
	int	i;

	i = 1;
	while (i < ac && '-' == av[i][0])
	{
		e->heur = 1;
		ft_get_heuristic(e, av[i]);
		i++;
	}
	if (e->heur == 0)
		ft_error("Choose a valid heuristic.\n-help to see options.");
	return (i);
}

static void	ft_init(t_env *e)
{
	ft_bzero(e, sizeof(t_env));
	e->solv = -1;
	e->heur = 0;
	e->man = 0;
	e->ham = 0;
	e->lin = 0;
	e->oor = 0;
	e->mxs = 0;
}

int			main(int ac, char **av)
{
	t_env	e;
	int		i;

	ft_init(&e);
	if (ac > 1)
	{
		i = ft_options(&e, ac, av);
		if (i == ac)
			ft_error("specify a puzzle");
		else if (i == ac - 1)
		{
			if ((e.fd = open(av[i], O_RDONLY)) == -1)
				ft_error("open failed");
		}
		else
			ft_error("specify only one puzzle");
		ft_read(&e);
		if (e.fd != STDIN)
			close(e.fd);
		ft_astar_init(&e);
		ft_ncurses(&e);
	}
	else
		ft_error("Choose a heuristic (-help) and submit a puzzle.");
	return (0);
}
