/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap_top_test.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zharzi <zharzi@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/12 11:28:59 by zharzi            #+#    #+#             */
/*   Updated: 2022/08/17 09:22:38 by zharzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pswap.h"

void	ft_pswap_view(t_list **astack, t_list **bstack, t_control *val);

void	ft_swap_top_test(t_list **astack, t_list **bstack, t_control *val)
{
	t_list	*ta1;
	t_list	*ta2;
	t_list	*tb1;
	t_list	*tb2;

	ta1 = NULL;
	tb1 = NULL;
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
	if (ta1 && tb1 && val->pop_a && val->pop_b && \
	ft_test_index(ta1, ta2) == 1 && ft_test_index(tb1, tb2) == -1)
		ft_move_ss(astack, bstack);
	else if (ta1 && val->pop_a && ft_test_index(ta1, ta2) == 1)
		ft_move_sa(astack);
	else if (tb1 && val->pop_b && ft_test_index(tb1, tb2) == -1)
		ft_move_sb(bstack);
	ft_pswap_view(astack, bstack, val);
}
