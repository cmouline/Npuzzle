/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecouderc <ecouderc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/04 21:03:38 by ecouderc          #+#    #+#             */
/*   Updated: 2014/11/06 21:37:51 by ecouderc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *s1, const char *s2, size_t n)
{
	size_t	i;
	size_t	s1len;
	size_t	s2len;
	size_t	min;

	s1len = ft_strlen(s1);
	s2len = ft_strlen(s2);
	min = (s1len < n) ? s1len : n;
	if (s2len == 0)
		return ((char *)(s1));
	if (s2len > min)
		return (NULL);
	i = 0;
	while (i <= min - s2len)
	{
		if (ft_strncmp(s1 + i, s2, s2len) == 0)
			return ((char*)(s1 + i));
		i++;
	}
	return (NULL);
}
