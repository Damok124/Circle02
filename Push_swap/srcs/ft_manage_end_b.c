/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_manage_end_b.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zharzi <zharzi@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/17 22:22:51 by zharzi            #+#    #+#             */
/*   Updated: 2022/08/22 15:57:55 by zharzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pswap.h"

void	ft_manage_end_b(t_list **bstack, t_control *val)
{
	t_list	*tmp1;
	t_list	*tmp2;
	int		test;

	ft_printf("\tmanage end b\n");
	tmp1 = ft_lstlast(*bstack);
	tmp2 = ft_lst_find_one(*bstack, val->pop_b + val->pop_eb -1);
	test = ft_test_index(*bstack, tmp1);
	if (test || tmp1->index > tmp2->index)
		ft_move_rrb(bstack, val);
	if (test == -1 && val->pop_b > 1)
		ft_move_sb(bstack, val);
}
