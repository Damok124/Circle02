/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap_test_top.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zharzi <zharzi@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/12 11:28:59 by zharzi            #+#    #+#             */
/*   Updated: 2022/08/12 11:29:55 by zharzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pswap.h"

void	ft_swap_test_top(t_list **astack, t_list **bstack)
{
	t_list	*ta1;
	t_list	*ta2;
	t_list	*tb1;
	t_list	*tb2;

	if (*astack && (*astack)->next)
	{
		ta1 = *astack;
		ta2 = ta1->next;
	}
	if (*bstack && (*bstack)->next)
	{
		tb1 = *bstack;
		tb2 = tb1->next;
	}
	if (ta1 && tb1)
	{
		if (ta1->index == (ta2->index + 1) && tb1->index == (tb2->index - 1))
			ft_move_ss(astack, bstack);
		if (ta1->index == (ta2->index + 1))
			ft_move_sa(astack);
		if (tb1->index == (tb2->index - 1))
			ft_move_sb(bstack);
	}
}
