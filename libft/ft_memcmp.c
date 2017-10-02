/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecouderc <ecouderc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/05 14:37:55 by ecouderc          #+#    #+#             */
/*   Updated: 2014/11/24 16:39:27 by ecouderc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t		i;

	i = 0;
	while (i < n)
	{
		if (*(unsigned char*)(s1 + i) == *(unsigned char*)(s2 + i))
			i++;
		else
			return (*(unsigned char*)(s1 + i) - *(unsigned char*)(s2 + i));
	}
	return (0);
}
