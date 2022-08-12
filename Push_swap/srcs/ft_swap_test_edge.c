/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap_test_edge.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zharzi <zharzi@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/12 11:29:03 by zharzi            #+#    #+#             */
/*   Updated: 2022/08/12 11:31:08 by zharzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pswap.h"

void	ft_swap_test_edge(t_list **astack, t_list **bstack, t_control *val)
{
	t_list	*ta1;
	t_list	*ta2;
	t_list	*tb1;
	t_list	*tb2;

	ta1 = *astack;
	ta2 = ft_lstlast(*astack);
	tb1 = *bstack;
	tb2 = ft_lstlast(*bstack);
	if (ta1->index == (ta2->index - 1) && tb1->index == (tb2->index + 1))
	{
		ft_move_rra(astack, val);
		ft_move_rrb(bstack, val);
		ft_move_ss(astack, bstack);
	}
	if (ta1->index == (ta2->index - 1))
	{
		ft_move_rra(astack, val);
		ft_move_sa(astack);
	}
	if (tb1->index == (tb2->index + 1))
	{
		ft_move_rrb(bstack, val);
		ft_move_sb(bstack);
	}
}
