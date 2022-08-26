/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rotate_tests.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zharzi <zharzi@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/17 22:40:52 by zharzi            #+#    #+#             */
/*   Updated: 2022/08/24 21:23:42 by zharzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pswap.h"

void	ft_rotate_tests(t_list **astack, t_list **bstack, t_control *val)
{
	t_list	*ta1;
	t_list	*ta2;

	ft_printf("\trotate test a\n");
	ta1 = *astack;
	ta2 = ft_lstlast(*astack);
	if (!ta1 || !ta2 || ta1 == ta2 || ft_is_lock(ta1, astack, val) \
	|| ft_is_lock(ta2, astack, val))
	{
		ft_rotate_test_b(astack, bstack, val);
		ft_swap_test_b(astack, bstack, val);
		return ;
	}
	if (ft_test_index(ta1, ta2) == 1 && !val->lock)
		ft_move_ra(astack, val);
	else if (ft_test_index(ta1, ta2) == -1 && (val->pop_ea || !val->lock))
		ft_move_rra(astack, val);
	ft_rotate_test_b(astack, bstack, val);
	ft_swap_test_b(astack, bstack, val);
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
