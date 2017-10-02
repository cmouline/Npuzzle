/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_heuristic.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecouderc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/25 18:24:19 by ecouderc          #+#    #+#             */
/*   Updated: 2015/04/28 15:58:53 by ecouderc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "npuzzle.h"

int			heuristic_cost_estimate(t_env *e, t_state *state)
{
	int	cost;

	cost = 0;
	if (e->man == 1)
		cost += ft_manhattan(e, state);
	if (e->ham == 1)
		cost += ft_hamming(e, state);
	if (e->lin == 1)
		cost += ft_linear(e, state);
	if (e->oor == 1)
		cost += ft_outof(e, state);
	if (e->mxs == 1)
		cost += ft_maxswap(e, state);
	return (cost);
}
