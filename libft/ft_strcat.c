/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecouderc <ecouderc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/04 16:32:52 by ecouderc          #+#    #+#             */
/*   Updated: 2014/11/24 17:31:46 by ecouderc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcat(char *dest, const char *src)
{
	int		i;
	int		srclen;
	int		destlen;

	srclen = ft_strlen(src);
	destlen = ft_strlen(dest);
	i = 0;
	while (i <= srclen)
	{
		dest[i + destlen] = src[i];
		i++;
	}
	return (dest);
}
