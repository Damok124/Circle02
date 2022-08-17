/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_reborn_astack.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zharzi <zharzi@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/17 22:41:34 by zharzi            #+#    #+#             */
/*   Updated: 2022/08/17 22:42:16 by zharzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pswap.h"

void	ft_reborn_astack(t_list **astack, t_list **bstack, t_control *val)
{
	if (!val->lock && !val->pop_a && val->pop_ea)
	{
		val->pop_a = val->pop_ea;
		val->pop_ea = 0;
	}
	if (val->lock && !val->pop_a && val->pop_ea)
	{
		while (val->pop_ea && !ft_pswap_final(astack, bstack, val))
		{
			ft_move_rra(astack, val);
			ft_rotate_test(astack, bstack, val);
			if (val->pop_a > 1)
				ft_swap_top_test(astack, bstack, val);
		}
	}
	//else remplir a intelligemment, surtout si du lock
	//
	//
	//
}
