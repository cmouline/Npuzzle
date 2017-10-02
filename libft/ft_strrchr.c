/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecouderc <ecouderc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/04 21:39:48 by ecouderc          #+#    #+#             */
/*   Updated: 2014/11/24 16:55:01 by ecouderc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		i;
	char	*s2;

	s2 = NULL;
	i = 0;
	while (s[i])
	{
		if (s[i] == (char)c)
			s2 = ((char*)(s + i));
		i++;
	}
	if (s[i] == (char)c)
		s2 = ((char*)(s + i));
	return (s2);
}
