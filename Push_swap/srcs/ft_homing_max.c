/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_homing_max.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zharzi <zharzi@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/17 22:43:22 by zharzi            #+#    #+#             */
/*   Updated: 2022/08/26 17:38:37 by zharzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pswap.h"

void	ft_homing_max(t_list **astack, t_list **bstack, t_control *val)
{
	t_list		*tmp;
	int			rank;

	ft_homing_booster(astack, bstack, val);
	tmp = *astack;
	rank = 0;
	while (tmp && tmp->index != val->max && ++rank)
		tmp = tmp->next;
	if (!val->lock && rank >= ft_lstsize(*astack) / 2)
	{
		val->pop_a = rank;
		val->lock++;
		val->max--;
		val->pop_ea = \
		val->ac - (val->pop_a + val->lock) - (val->pop_b + val->pop_eb);
	}
}
