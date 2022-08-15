/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap_test.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zharzi <zharzi@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/12 11:29:03 by zharzi            #+#    #+#             */
/*   Updated: 2022/08/15 20:48:06 by zharzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pswap.h"

int	ft_swap_test(t_list **astack, t_list **bstack, t_control *values)
{
	//t_list	*ta1;
	t_list	*tb1;
	t_list	*tb2;
	int		check;

	//ta1 = NULL;
	tb1 = NULL;
	check = 0;
	//if (*astack && (*astack)->next)
	//{
	//	ta1 = *astack;
	//	ta2 = ft_lstlast(ta1);
	//}
	if (*bstack && (*bstack)->next)
	{
		tb1 = *bstack;
		tb2 = ft_lstlast(tb1);
	}
	if (tb1 && ft_swap_test_index(tb1, tb2) == -1)
	{
		ft_move_rrb(bstack, values);
		check = 1;
	}
	ft_swap_top_test(astack, bstack, values);
	return (check);
}
