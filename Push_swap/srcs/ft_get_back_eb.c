/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_back_eb.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zharzi <zharzi@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/21 12:05:59 by zharzi            #+#    #+#             */
/*   Updated: 2022/08/21 12:06:03 by zharzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pswap.h"

void	ft_get_back_eb(t_list **astack, t_list **bstack, t_control *val)
{
	t_list	*tmp1;
	t_list	*tmp2;

	tmp1 = NULL;
	tmp2 = NULL;
	if (val->pop_a && *bstack)
	{
		tmp1 = *astack;
		tmp2 = ft_lstlast(*bstack);
	}
	if (ft_test_index(tmp1, tmp2))
	{
		ft_move_rrb(bstack, val);
		ft_move_pa(astack, bstack, val);
		ft_swap_top_test(astack, bstack, val);
	}
}
