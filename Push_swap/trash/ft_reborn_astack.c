/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_reborn_astack.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zharzi <zharzi@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/17 22:41:34 by zharzi            #+#    #+#             */
/*   Updated: 2022/08/20 23:06:03 by zharzi           ###   ########.fr       */
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
	else if (val->lock && val->pop_ea)
	{
		if (val->pop_ea && !ft_pswap_final(astack, bstack, val))
		{
			if (val->pop_a > 1)
				ft_swap_top_test(astack, bstack, val);
			else if (val->pop_ea)
			{
				ft_move_rra(astack, val);
				ft_swap_top_test(astack, bstack, val);
			}
			if (!ft_is_lock(*astack, astack, val) \
			&& (*astack)->index < ft_find_lstavg(astack))
			{
				ft_push_to_b(astack, bstack, val);
				ft_swap_test_b(astack, bstack, val);
			}
		}
	}
}
//tester ensuite avec distri avg a // BUGGGGGG
