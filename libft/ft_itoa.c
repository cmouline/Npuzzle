/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecouderc <ecouderc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/06 12:56:11 by ecouderc          #+#    #+#             */
/*   Updated: 2014/11/24 17:43:08 by ecouderc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

int		ft_len(int n)
{
	int		len;

	len = 1;
	n /= 10;
	n = (n < 0) ? -n : n;
	while (n > 0)
	{
		n /= 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	char	*s;
	int		i;
	int		len;
	int		sign;

	sign = (n < 0) ? -1 : 1;
	len = ft_len(n);
	len = (n < 0) ? len + 1 : len;
	s = (char*)malloc(sizeof(*s) * (len + 1));
	if (s == NULL)
		return (NULL);
	s[len] = '\0';
	i = len - 1;
	while (i >= 0)
	{
		s[i] = '0' + (n % 10) * sign;
		n /= 10;
		i--;
	}
	if (sign < 0)
		s[0] = '-';
	return (s);
}
