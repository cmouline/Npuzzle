/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmouline <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/25 19:51:05 by cmouline          #+#    #+#             */
/*   Updated: 2015/04/24 21:07:53 by ecouderc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "npuzzle.h"

void	ft_printgrid(t_env *e)
{
	int	i;
	int	j;

	i = 0;
	while (i < e->size)
	{
		j = 0;
		while (j < e->size)
		{
			ft_putnbr(e->tab[i][j]);
			ft_putchar(' ');
			j++;
		}
		ft_putchar('\n');
		i++;
	}
}
