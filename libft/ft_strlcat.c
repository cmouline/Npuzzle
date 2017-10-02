/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecouderc <ecouderc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/04 17:22:10 by ecouderc          #+#    #+#             */
/*   Updated: 2014/11/12 19:14:34 by ecouderc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_strlcat(char *dst, const char *src, size_t size)
{
	int			i;
	size_t		srclen;
	size_t		dstlen;
	int			flen;

	dstlen = 0;
	while (dst[dstlen] && dstlen < size)
		dstlen++;
	srclen = ft_strlen(src);
	flen = (int)size - (int)dstlen - 1;
	i = 0;
	while (i < (int)srclen && i < flen)
	{
		dst[i + dstlen] = src[i];
		i++;
	}
	if (flen >= 0)
		dst[i + dstlen] = '\0';
	return (dstlen + srclen);
}
