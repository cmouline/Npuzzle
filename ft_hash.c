/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hash.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecouderc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/27 17:39:46 by ecouderc          #+#    #+#             */
/*   Updated: 2015/03/27 21:34:55 by ecouderc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "npuzzle.h"

#define GET16BITS(d)	(*((const uint16_t *)(d)))

static void	ft_rem(const char *data, int rem, uint32_t *hash)
{
	if (rem == 3)
	{
		*hash += GET16BITS(data);
		*hash ^= *hash << 16;
		*hash ^= ((signed char)data[sizeof(uint16_t)]) << 18;
		*hash += *hash >> 11;
	}
	else if (rem == 2)
	{
		*hash += GET16BITS(data);
		*hash ^= *hash << 11;
		*hash += *hash >> 17;
	}
	else if (rem == 1)
	{
		*hash += (signed char)(*data);
		*hash ^= *hash << 10;
		*hash += *hash >> 1;
	}
	*hash ^= *hash << 3;
	*hash += *hash >> 5;
	*hash ^= *hash << 4;
	*hash += *hash >> 17;
	*hash ^= *hash << 25;
	*hash += *hash >> 6;
}

uint32_t	hash(const char *data, int len)
{
	uint32_t	hash;
	uint32_t	tmp;
	int			rem;

	hash = len;
	if (len <= 0 || data == NULL)
		return (0);
	rem = len & 3;
	len >>= 2;
	while (len > 0)
	{
		hash += GET16BITS(data);
		tmp = (GET16BITS(data + 2) << 11) ^ hash;
		hash = (hash << 16) ^ tmp;
		data += 2 * sizeof(uint16_t);
		hash += hash >> 11;
		len--;
	}
	ft_rem(data, rem, &hash);
	return (hash);
}
