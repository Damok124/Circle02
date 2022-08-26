/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_update_thirds.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zharzi <zharzi@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/23 14:59:07 by zharzi            #+#    #+#             */
/*   Updated: 2022/08/25 14:19:18 by zharzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pswap.h"

void	ft_update_thirds(t_control *val, int criteria)
{
	ft_printf("\tupdate thirds a\n");
	if (criteria == 0)
	{
		val->firstthird = val->ac / 3;
		val->lastthird = val->ac / 3 * 2;
	}
	if (criteria == 1)
	{
		val->firstthird = (val->max - val->min) / 3;
		val->lastthird = (val->max - val->min) / 3 * 2;
	}
	if (criteria == 2)
	{
		val->firstthird = val->lastthird + ((val->max - val->min - val->lastthird) / 3);
		val->lastthird = val->lastthird + ((val->max - val->min - val->lastthird) / 3 * 2);
	}
}
