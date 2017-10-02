/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tab.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecouderc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/27 17:48:23 by ecouderc          #+#    #+#             */
/*   Updated: 2015/04/25 17:24:34 by ecouderc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "npuzzle.h"

int				**ft_tab_cpy(t_env *e, int **tab)
{
	int			**tmp;
	int			i;
	int			j;

	if (!(tmp = (int **)malloc(sizeof(int *) * e->size)))
		exit(1);
	i = 0;
	while (i < e->size)
	{
		if (!(tmp[i] = (int *)malloc(sizeof(int) * e->size)))
			exit(1);
		j = 0;
		while (j < e->size)
		{
			tmp[i][j] = tab[i][j];
			j++;
		}
		i++;
	}
	return (tmp);
}

void			ft_tab_free(t_env *e, int **tab)
{
	int			i;

	i = 0;
	while (i < e->size)
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}

int				ft_tab_comp(t_env *e, int **tab1, int **tab2)
{
	int			i;
	int			j;

	i = 0;
	while (i < e->size)
	{
		j = 0;
		while (j < e->size)
		{
			if (tab1[i][j] != tab2[i][j])
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}
