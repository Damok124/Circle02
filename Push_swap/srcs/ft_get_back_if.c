/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_back_if.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zharzi <zharzi@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/21 12:06:17 by zharzi            #+#    #+#             */
/*   Updated: 2022/08/24 18:23:38 by zharzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pswap.h"

void	ft_get_back_if(t_list **astack, t_list **bstack, t_control *val)
{
	t_list	*tmp1;
	t_list	*tmp2;

	tmp1 = *astack;
	tmp2 = *bstack;
//	ft_printf("\tget back if\n");
	if (tmp1 && tmp2 && val->pop_a && (val->pop_b || val->pop_eb))
	{
		if (ft_test_index(tmp1, tmp2))
		{
			ft_move_pa(astack, bstack, val);
			ft_swap_top_test(astack, bstack, val);
		}
		else if (!ft_test_index(tmp1, tmp2))
			ft_get_back_eb(astack, bstack, val);
	}
	else if ((!tmp1 || !val->pop_a) && tmp2)
	{/*
		tmp1 = ft_lstlast(*bstack);
		if (!ft_index_comp(tmp2, tmp1))
			ft_get_from_eb(astack, bstack, val);
		else
			ft_get_from_b(astack, bstack, val);*/
		ft_ending_bstack(astack, bstack, val);
	}
	ft_pswap_view(astack, bstack, val);
}
