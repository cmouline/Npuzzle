/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecouderc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/27 21:24:57 by ecouderc          #+#    #+#             */
/*   Updated: 2015/03/24 15:35:57 by ecouderc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "npuzzle.h"

void	ft_error(char *s)
{
	ft_putstr_fd(RED, STDERR);
	ft_putstr_fd("npuzzle: ", STDERR);
	ft_putstr_fd(s, STDERR);
	ft_putstr_fd(WHITE, STDERR);
	ft_putchar('\n');
	exit(1);
}
