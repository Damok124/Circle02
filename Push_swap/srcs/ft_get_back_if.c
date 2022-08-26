/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_back_if.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zharzi <zharzi@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/21 12:06:17 by zharzi            #+#    #+#             */
/*   Updated: 2022/08/26 17:28:02 by zharzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pswap.h"

void	ft_get_back_if(t_list **astack, t_list **bstack, t_control *val)
{
	t_list	*tmp1;
	t_list	*tmp2;

	tmp1 = *astack;
	tmp2 = *bstack;
	if (tmp1 && tmp2 && val->pop_a && (val->pop_b || val->pop_eb))
	{
		if (ft_test_index(tmp1, tmp2))
		{
			ft_move_pa(astack, bstack, val);
			ft_swap_top_test(astack, bstack, val);
		}
		else if (!ft_test_index(tmp1, tmp2))
			ft_get_back_eb(astack, bstack, val);
		else if (tmp2)
			ft_ending_bstack(astack, bstack, val);
	}
	else if ((!tmp1 || !val->pop_a) && tmp2)
		ft_ending_bstack(astack, bstack, val);
}