/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecouderc <ecouderc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/04 18:47:56 by ecouderc          #+#    #+#             */
/*   Updated: 2014/11/24 17:38:02 by ecouderc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strdup(const char *src)
{
	char	*dest;
	int		len;

	len = ft_strlen(src);
	dest = (char*)malloc(sizeof(*dest) * (len + 1));
	if (dest != NULL)
		ft_strcpy(dest, src);
	return (dest);
}
