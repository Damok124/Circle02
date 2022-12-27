/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap_test_b.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zharzi <zharzi@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/12 11:29:03 by zharzi            #+#    #+#             */
/*   Updated: 2022/08/26 17:43:59 by zharzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pswap.h"

int	ft_swap_test_b(t_list **astack, t_list **bstack, t_control *val)
{
	t_list	*tmp1;
	t_list	*tmp2;
	int		check;

	tmp1 = NULL;
	check = 0;
	if (*bstack && (*bstack)->next)
	{
		tmp1 = *bstack;
		tmp2 = ft_lstlast(tmp1);
	}
	if (tmp1 && !ft_index_comp(tmp1, tmp2))
	{
		ft_move_rrb(bstack, val);
		check = 1;
	}
	ft_swap_top_test(astack, bstack, val);
	return (check);
}
