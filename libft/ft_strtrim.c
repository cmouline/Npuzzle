/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecouderc <ecouderc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/06 10:36:30 by ecouderc          #+#    #+#             */
/*   Updated: 2014/11/16 19:37:23 by ecouderc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	char			*s2;
	int				i;
	int				start;
	int				end;

	i = 0;
	while (s[i] && (s[i] == ' ' || s[i] == '\n' || s[i] == '\t'))
		i++;
	start = i;
	i = ft_strlen(s) - 1;
	while (i >= 0 && (s[i] == ' ' || s[i] == '\n' || s[i] == '\t'))
		i--;
	end = i;
	if (end - start + 1 < 0)
		s2 = ft_strsub(s, 0, 0);
	else
		s2 = ft_strsub(s, start, end - start + 1);
	return (s2);
}
