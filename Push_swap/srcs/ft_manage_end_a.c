/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_manage_end_a.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zharzi <zharzi@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/17 22:22:51 by zharzi            #+#    #+#             */
/*   Updated: 2022/08/22 15:57:47 by zharzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pswap.h"

void	ft_manage_end_a(t_list **astack, t_list **bstack, t_control *val)
{
	t_list	*tmp1;
	t_list	*tmp2;
	int		test;

	ft_lock_elem(astack, bstack, &val);
	ft_printf("\tmanage end a\n");
	tmp1 = ft_lstlast(*astack);
	tmp2 = ft_lst_find_one(*astack, val->pop_a + val->lock + val->pop_ea -1);
	test = ft_test_index(*astack, tmp1);
	if (test || tmp1->index < tmp2->index)
		ft_move_rra(astack, val);
	if (test == -1)
		ft_move_sa(astack, val);
}
