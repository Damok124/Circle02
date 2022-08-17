/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rotation_test_a.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zharzi <zharzi@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/17 22:40:52 by zharzi            #+#    #+#             */
/*   Updated: 2022/08/17 22:40:58 by zharzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pswap.h"

void	ft_rotate_test_a(t_list **astack, t_list **bstack, t_control *val)
{
	t_list	*ta1;
	t_list	*ta2;
	//t_list	*tb1;
	//t_list	*tb2;

	ft_printf("\trotate test\n");
	ta1 = *astack;
	//tb1 = *bstack;
	if (ta1 && (val->pop_a + val->lock + val->pop_ea) > 1)
		ta2 = ft_lstlast(*astack);
	//if (tb1 && (val->pop_b + val->pop_eb) > 1)
	//	tb2 = ft_lstlast(*bstack);
	if (ta1 && ta2/* && tb1 && tb2*/)
	{
		if (ft_test_index(ta1, ta2))
		{
			if (ta2->index < ta1->index)
				ft_move_ra(astack, val);
			else
			{
				ft_move_rra(astack, val);
			}
			ft_swap_test(astack, bstack, val);
		}
	}
	ft_pswap_view(astack, bstack, val);
}
