/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ending_eastack.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zharzi <zharzi@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/17 22:40:36 by zharzi            #+#    #+#             */
/*   Updated: 2022/08/26 16:03:50 by zharzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pswap.h"

void	ft_ending_eastack(t_list **astack, t_list **bstack, t_control *val)
{
	ft_printf("\tending eastack, multi rra\n");
	while (val->pop_ea)
	{
		if (!(*bstack))
		{
			if (val->ac > 3 && val->pop_a && ft_index_comp(ft_lstlast(*astack), *astack))
			{
				ft_move_pb(astack, bstack, val);
				while (ft_test_index(*astack, *bstack))//new
					ft_move_pb(astack, bstack, val);
			}
			else if (val->pop_ea)//rajout else
				ft_move_rra(astack, val);
		}
		ft_swap_top_test(astack, bstack, val);
		if (*bstack && val->pop_ea && ft_lstsize(*astack) > 1)
		{
			if (!ft_index_comp(ft_lstlast(*astack), *bstack))
			{
				if ((ft_lstsize(*bstack) > 1 && \
				ft_index_comp(*bstack, ft_lstlast(*bstack))) \
				|| ft_lstsize(*bstack) == 1)
					ft_get_from_b(astack, bstack, val);
				else
					ft_get_from_eb(astack, bstack, val);
			}
			ft_move_rra(astack, val);
		}
		ft_swap_top_test(astack, bstack, val);
	}
}
/*
si le dernier est plus grand que
*/
/*if (!ft_is_lock(ft_lstlast(*astack), astack, val) \
		&& !ft_index_comp(ft_lstlast(*astack), *bstack))
			ft_get_back_if(astack, bstack, val);
		else if (!ft_is_lock(ft_lstlast(*astack), astack, val) \
		&& ft_index_comp(ft_lstlast(*astack), *bstack))
			ft_get_from_ea(astack, bstack, val);
		else if (val->pop_a && !ft_index_comp(*astack, ft_lstlast(*astack)) \
		&& val->pop_ea && !ft_test_index(*astack, ft_lst_find_one(*astack, 1)))
		{
			if (!ft_is_lock(*astack, astack, val))
				ft_move_pb(astack, bstack, val);
			ft_swap_top_test(astack, bstack, val);
			ft_move_rra(astack, val);
			ft_swap_top_test(astack, bstack, val);
		}
*/
