/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_small.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zharzi <zharzi@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/20 21:36:38 by zharzi            #+#    #+#             */
/*   Updated: 2022/08/26 17:55:52 by zharzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pswap.h"

void	ft_small_end(t_list **astack, t_list **bstack, t_control *val)
{
	if (val->pop_a > 1 && !ft_pswap_final(astack, bstack, val))
	{
		ft_move_pb(astack, bstack, val);
		ft_swap_test_b(astack, bstack, val);
		ft_small(astack, bstack, val);
	}
	else if (!ft_pswap_final(astack, bstack, val))
	{
		while (val->pop_b && !ft_pswap_final(astack, bstack, val))
		{
			if (val->pop_a && !ft_index_comp(*astack, ft_lstlast(*bstack)))
				ft_push_to_eb(astack, bstack, val);
			while (*bstack && !ft_pswap_final(astack, bstack, val))
				ft_get_back_if(astack, bstack, val);
			if (val->pop_a < 2)
				ft_ending_bstack(astack, bstack, val);
			ft_small(astack, bstack, val);
		}
	}
}

void	ft_small(t_list **astack, t_list **bstack, t_control *val)
{
	if (ft_pswap_final(astack, bstack, val))
		return ;
	ft_put_end(astack, val, 1);
	if (!val->lock && !ft_pswap_final(astack, bstack, val))
		ft_homing_max(astack, bstack, val);
	while (ft_lock_elem(astack, &val))
		;
	if (val->lock && val->pop_ea && !ft_pswap_final(astack, bstack, val))
		ft_ending_eastack(astack, bstack, val);
	if (!ft_pswap_final(astack, bstack, val))
		ft_swap_test_b(astack, bstack, val);
	ft_small_end(astack, bstack, val);
}
