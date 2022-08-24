/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_small.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zharzi <zharzi@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/20 21:36:38 by zharzi            #+#    #+#             */
/*   Updated: 2022/08/24 21:24:51 by zharzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pswap.h"

/*8 32 72 35 15 43 21 39 17 30 95 64 79 54 82 62 27 84 23 94 7 37 76 40 88 51 74 81 44 41 57 14 93 24 13 12 70 18 26 47 10 75 73 56 98 71 59 69 38 58 96 2 89 97 60 49 36 42 99 85 83 66 25 34 48 52 63 20 100 67 65 46 11 16 77 31 45 78 53 68 1 6 4 91 5 33 61 92 55 90 28 22 87 80 3 19 86 9 50 29
*/
void	ft_small(t_list **astack, t_list **bstack, t_control *val)
{
	if (!val->lock && !ft_pswap_final(astack, bstack, val))
		ft_homing_max(astack, bstack, val);
	while (ft_lock_elem(astack, bstack, &val))
		;
	if (!ft_pswap_final(astack, bstack, val))//nouveau
		ft_rotate_tests(astack, bstack, val);//nouveau
	if (val->lock && val->pop_ea && !ft_pswap_final(astack, bstack, val))
		ft_ending_eastack(astack, bstack, val);
	if (!ft_pswap_final(astack, bstack, val))
		ft_swap_test_b(astack, bstack, val);
	if (val->pop_a/* > 1 */&& !ft_pswap_final(astack, bstack, val))//2 au lieu de 1?
	{
		ft_move_pb(astack, bstack, val);
		ft_swap_test_b(astack, bstack, val);
		ft_small(astack, bstack, val);
	}
	else if (!ft_pswap_final(astack, bstack, val))
	{
		ft_pswap_view(astack, bstack, val);
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

/*
void	ft_small(t_list **astack, t_list **bstack, t_control *val)
{
	if (!val->lock && !ft_pswap_final(astack, bstack, val))
		ft_homing_max(astack, bstack, val);
	if (!val->lock && !ft_pswap_final(astack, bstack, val))
		ft_rotate_tests(astack, bstack, val);
	if (val->lock && !ft_pswap_final(astack, bstack, val))
		ft_ending_eastack(astack, bstack, val);
	if (!ft_pswap_final(astack, bstack, val))
		ft_swap_test_b(astack, bstack, val);
}
parfait pour 3 elem
*/
/*parfait pour 5 elem
void	ft_small(t_list **astack, t_list **bstack, t_control *val)
{
	if (ft_pswap_final(astack, bstack, val))
		return ;
	if (!val->lock && !ft_pswap_final(astack, bstack, val))
		ft_homing_max(astack, bstack, val);
	while (ft_lock_elem(astack, bstack, &val))
		;
	if (val->lock && val->pop_ea && !ft_pswap_final(astack, bstack, val))
		ft_ending_eastack(astack, bstack, val);
	if (!ft_pswap_final(astack, bstack, val))
		ft_swap_test_b(astack, bstack, val);
	if (val->pop_a > 1 && !ft_pswap_final(astack, bstack, val))
	{
		ft_move_pb(astack, bstack, val);
		ft_swap_test_b(astack, bstack, val);
		ft_small(astack, bstack, val);
	}
	else if (!ft_pswap_final(astack, bstack, val))
	{
		ft_pswap_view(astack, bstack, val);
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
*/
