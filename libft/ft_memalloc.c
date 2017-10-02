/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecouderc <ecouderc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/05 18:29:40 by ecouderc          #+#    #+#             */
/*   Updated: 2014/11/24 17:39:30 by ecouderc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	*ft_memalloc(size_t size)
{
	void	*s;

	if (size == 0)
		return (NULL);
	s = (void*)malloc(size);
	if (s == NULL)
		return (NULL);
	bzero(s, size);
	return (s);
}
