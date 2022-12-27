/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ending_bstack.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zharzi <zharzi@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/07 17:29:50 by zharzi            #+#    #+#             */
/*   Updated: 2022/08/26 17:25:39 by zharzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pswap.h"

void	ft_ending_bstack(t_list **astack, t_list **bstack, t_control *val)
{
	t_list	*tmp;

	val->pop_b += val->pop_eb;
	val->pop_eb = 0;
	while (*bstack)
	{
		tmp = ft_lstlast(*bstack);
		if ((*bstack)->index < tmp->index)
			ft_move_rrb(bstack, val);
		ft_move_pa(astack, bstack, val);
		ft_swap_top_test(astack, bstack, val);
	}
}
