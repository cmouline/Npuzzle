/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecouderc <ecouderc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/06 12:15:21 by ecouderc          #+#    #+#             */
/*   Updated: 2014/11/24 17:42:52 by ecouderc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_word(const char *str, int len, int i)
{
	int			j;
	char		*strw;

	strw = (char*)malloc(sizeof(*strw) * (len + 1));
	if (strw != NULL)
	{
		j = 0;
		while (j < len)
		{
			strw[j] = str[i + j];
			j++;
		}
		strw[j] = '\0';
	}
	return (strw);
}

int		ft_count(char const *s, char c)
{
	size_t		i;
	int			k;
	int			len;

	i = 0;
	k = 0;
	len = 0;
	while (i < ft_strlen(s))
	{
		if (s[i] == c)
		{
			if (len > 0)
			{
				k++;
				len = 0;
			}
		}
		else
			len++;
		i++;
	}
	if (len > 0)
		k++;
	return (k);
}

char	**ft_strsplit(char const *s, char c)
{
	size_t		i;
	int			k;
	int			len;
	char		**tab;

	if (!(tab = (char**)malloc(sizeof(*tab) * (ft_count(s, c) + 1))))
		return (NULL);
	i = 0;
	k = 0;
	len = 0;
	while (i < ft_strlen(s))
	{
		if (s[i] == c && len > 0 && !(tab[k++] = ft_word(s, len, i - len)))
			return (NULL);
		if (s[i] == c)
			len = 0;
		else
			len++;
		i++;
	}
	if (len > 0 && !(tab[k++] = ft_word(s, len, ft_strlen(s) - len)))
		return (NULL);
	tab[k] = 0;
	return (tab);
}
