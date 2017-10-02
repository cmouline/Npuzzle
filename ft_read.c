/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmouline <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/24 15:54:06 by cmouline          #+#    #+#             */
/*   Updated: 2015/07/04 22:09:28 by ecouderc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "npuzzle.h"

static int	ft_check_tile(t_env *e, int current)
{
	int i;
	int j;
	int match;

	i = 0;
	match = 0;
	while (i < e->size)
	{
		j = 0;
		while (j < e->size)
		{
			if (current == e->state_0.tab[i][j])
				match++;
			j++;
		}
		i++;
	}
	return (match);
}

static void	ft_check_grid(t_env *e, int n)
{
	int current;
	int match;
	int k;

	k = 0;
	if (n != e->size)
		ft_error("corrupted file");
	while (k < e->size * e->size)
	{
		current = e->state_0.tab[k / e->size][k % e->size];
		if (current < 0 || current > e->size * e->size - 1)
			ft_error("invalid grid");
		match = ft_check_tile(e, current);
		if (match > 1)
			ft_error("invalid grid");
		k++;
	}
}

static void	ft_getsize(t_env *e)
{
	char	*str;
	int		i;

	str = NULL;
	while ((get_next_line(e->fd, &str)) == 1)
	{
		i = 0;
		if (str[i] != '#')
		{
			while (str[i] >= '0' && str[i] <= '9')
				i++;
			if (str[i] == '\0' && i > 0)
			{
				e->size = ft_atoi(str);
				if (e->size < 2 || e->size > 100)
					ft_error("size must be between 2 and 100");
				free(str);
				return ;
			}
			else
				ft_error("corrupted file");
		}
		free(str);
	}
	ft_error("corrupted file");
}

static void	ft_filltab(t_env *e, char **table, int i)
{
	int j;

	j = 0;
	while (table[j])
	{
		if (j >= e->size)
			ft_error("corrupted file");
		if ((e->state_0.tab[i][j] = ft_atoi(table[j])) == 0)
		{
			e->state_0.start.i = i;
			e->state_0.start.j = j;
		}
		free(table[j]);
		j++;
	}
	if (j != e->size)
		ft_error("corrupted file");
}

void		ft_read(t_env *e)
{
	char	*str;
	char	**table;
	int		i;

	str = NULL;
	i = 0;
	ft_getsize(e);
	if ((e->state_0.tab = (int**)malloc(sizeof(int*) * e->size)) == NULL)
		ft_error("malloc failed");
	while ((get_next_line(e->fd, &str)) == 1)
	{
		if (i >= e->size)
			ft_error("corrupted file");
		table = ft_split_whitespaces(str);
		if ((e->state_0.tab[i] = (int*)malloc(sizeof(int) * e->size)) == NULL)
			ft_error("malloc failed");
		ft_bzero(e->state_0.tab[i], sizeof(int) * e->size);
		ft_filltab(e, table, i);
		free(table), free(str);
		i++;
	}
	free(str);
	ft_check_grid(e, i);
}
