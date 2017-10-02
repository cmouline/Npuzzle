/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecouderc <ecouderc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/05 12:39:21 by ecouderc          #+#    #+#             */
/*   Updated: 2014/11/24 17:38:49 by ecouderc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t	i;
	void	*srcdup;

	srcdup = ft_strdup(src);
	i = 0;
	while (i < len)
	{
		*(unsigned char*)(dst + i) = *(unsigned char*)(srcdup + i);
		i++;
	}
	free(srcdup);
	return (dst);
}
