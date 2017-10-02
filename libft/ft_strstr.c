/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecouderc <ecouderc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/07/09 16:57:20 by ecouderc          #+#    #+#             */
/*   Updated: 2014/11/04 20:52:08 by ecouderc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *s1, const char *s2)
{
	size_t	i;
	size_t	s1len;
	size_t	s2len;

	s1len = ft_strlen(s1);
	s2len = ft_strlen(s2);
	if (s2len == 0)
	{
		return ((char *)(s1));
	}
	if (s2len > s1len)
		return (NULL);
	i = 0;
	while (i < s1len - s2len + 1)
	{
		if (ft_strncmp(s1 + i, s2, s2len) == 0)
			return ((char*)(s1 + i));
		i++;
	}
	return (NULL);
}
