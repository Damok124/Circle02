/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rotate_test_b.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zharzi <zharzi@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/17 22:40:52 by zharzi            #+#    #+#             */
/*   Updated: 2022/08/22 22:04:35 by zharzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pswap.h"

void	ft_rotate_test_b(t_list **astack, t_list **bstack, t_control *val)
{
	t_list	*tb1;
	t_list	*tb2;

	ft_printf("\trotate test b\n");
	tb1 = *bstack;
	tb2 = ft_lstlast(*bstack);
	if (!tb1 || !tb2 || tb1 == tb2)
		return ;
	if (ft_test_index(tb1, tb2) < 0)
		ft_move_rrb(bstack, val);
	else if (ft_test_index(tb1, tb2) > 0)
		ft_move_rb(bstack, val);
	ft_pswap_view(astack, bstack, val);
}
/*
int	ft_rotate_test_a(t_list **astack, t_list **bstack, t_control *val)
{
	t_list	*ta1;
	t_list	*ta2;
	int		done;

	done = 0;
	ft_printf("\trotate test\n");
	ta1 = *astack;
	if (!ta1 || ft_is_lock(ta1, astack, val))
		return (-1);
	if (ta1 && (val->pop_a + val->lock + val->pop_ea) > 1)
		ta2 = ft_lstlast(*astack);
	if (!ta2 || ft_is_lock(ta2, astack, val))
		return (-1);
	if (ft_test_index(ta1, ta2))
	{
		if (ta2->index < ta1->index)
			ft_move_ra(astack, val);
		else
			ft_move_rra(astack, val);
		ft_swap_test_b(astack, bstack, val);
		done = 1;
	}
	ft_pswap_view(astack, bstack, val);
	return (done);
}
*/
