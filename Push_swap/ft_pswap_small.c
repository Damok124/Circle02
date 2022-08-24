/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pswap_small.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zharzi <zharzi@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/17 22:44:06 by zharzi            #+#    #+#             */
/*   Updated: 2022/08/20 16:16:52 by zharzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pswap.h"

void	ft_smart_fill_b(t_list **astack, t_list **bstack, t_control *val)
{
	t_list	*tmp;
	int		loop;

	loop = 0;
	tmp = ft_lstlast(*astack);
	ft_printf("\tsmart fill b\n");
	if (val->pop_a > 3 && loop < 10)
	{
		ft_lock_elem(astack, bstack, &val);
		if (!val->lock && tmp->index <= val->firstthird)
			ft_move_rra(astack, val);
		if (ft_pswap_final(astack, bstack, val))
			return ;
		if (val->pop_a && (*astack)->index <= val->firstthird)
			ft_push_to_b(astack, bstack, val);
		if (ft_pswap_final(astack, bstack, val))
			return ;
		ft_manage_end_b(astack, val);
		if (ft_pswap_final(astack, bstack, val))
			return ;
		ft_manage_end_a(astack, bstack, val);
		if (ft_pswap_final(astack, bstack, val))
			return ;
		ft_swap_test_b(astack, bstack, val);
		if (ft_pswap_final(astack, bstack, val))
			return ;
		loop++;
	}
	if (loop == 10 && val->pop_a)
		ft_distri_avg_a(astack, bstack, val);
}

void	ft_manage_five(t_list **astack, t_list **bstack, t_control *val)
{
	int	loop;

	loop = 0;
	if (val->pop_a + val->lock + val->pop_ea > 3 && loop < 10)
	{
		ft_printf("\tmanage five\n");
		if ((*astack)->index <= (val->ac) / 2 \
		&& !ft_is_lock(*astack, astack, val))
			ft_push_to_b(astack, bstack, val);
		else if (ft_rotate_test_a(astack, bstack, val) == 0)
		{
			ft_manage_end_a(astack, bstack, val);
			ft_rotate_anyway(astack, bstack, val);
		}
		ft_swap_top_test(astack, bstack, val);
		loop++;
	}
	if (val->pop_a && val->pop_a + val->lock + val->pop_ea > 3)
	{
		ft_smart_fill_b(astack, bstack, val);
	}
}

void	ft_pswap_small(t_list **astack, t_list **bstack, t_control *val)
{
	ft_printf("\tpswap small\n");
	ft_lock_elem(astack, bstack, &val);
//	if ((val->pop_a + val->lock + val->pop_ea) > 3)
//		ft_manage_five(astack, bstack, val);
	if (ft_pswap_final(astack, bstack, val))
		return ;
	if (!ft_pswap_final(astack, bstack, val))
	{
		ft_lock_elem(astack, bstack, &val);
		ft_manage_end_a(astack, bstack, val);
		if (ft_pswap_final(astack, bstack, val))
			return ;
		ft_lock_elem(astack, bstack, &val);
		ft_swap_test_b(astack, bstack, val);
		if (ft_pswap_final(astack, bstack, val))
			return ;
		ft_lock_elem(astack, bstack, &val);
	}
	ft_pswap_view(astack, bstack, val);
	ft_printf("\tend pswap small\n");
}
/*
void	ft_pswap_small(t_list **astack, t_list **bstack, t_control *val)
{
	while (!ft_pswap_final(astack, bstack, val))
	{
		if ((*astack)->index > val->lastthird)
		{
			ft_push_to_ea(astack, val);
			if ((*astack)->index <= val->firstthird)
				ft_swap_test(astack, bstack, val);
			ft_rotate_test(astack, bstack, val);
		}
		while (!ft_pswap_final(astack, bstack, val))
		{
			ft_swap_test(astack, bstack, val);
			ft_rotate_test(astack, bstack, val);
		}
	}
}
*/
/*
void	ft_pswap_small(t_list **astack, t_list **bstack, t_control *val)
{
	while (!ft_pswap_final(astack, bstack, val))
	{
		ft_lock_elem(astack, bstack, &val);
		ft_swap_test(astack, bstack, val);
		if (ft_pswap_final(astack, bstack, val))
			return ;
		ft_lock_elem(astack, bstack, &val);
		ft_manage_end_a(astack, bstack, val);
		if (ft_pswap_final(astack, bstack, val))
			return ;
		ft_lock_elem(astack, bstack, &val);
	}
	ft_pswap_view(astack, bstack, val);
}
convient parfaitement avec jusqu'à trois element*/
