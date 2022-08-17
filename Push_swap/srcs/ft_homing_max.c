/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_homing_max.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zharzi <zharzi@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/17 22:43:22 by zharzi            #+#    #+#             */
/*   Updated: 2022/08/17 22:43:27 by zharzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pswap.h"

void	ft_homing_max(t_list **astack, t_list **bstack, t_control *val)
{
	t_list	*tmp;
	int		position;

	tmp = *astack;
	position = 0;
	while (tmp && tmp->index != val->max)
	{
		tmp = tmp->next;
		position++;
	}
	if (position)
	{
		if (tmp->index == val->max)
		{
			val->pop_a = position;
			val->lock += 1;
		}
		while (tmp)
		{
			tmp = tmp->next;
			position++;
		}
		val->pop_ea = position - val->pop_a - 1;
		ft_pswap_view(astack, bstack, val);
		ft_recall_eastack(astack, bstack, val);
	}
	else
		ft_move_ra(astack, val);
}
