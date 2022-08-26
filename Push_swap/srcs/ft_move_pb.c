/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move_pb.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zharzi <zharzi@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/24 04:57:31 by zharzi            #+#    #+#             */
/*   Updated: 2022/08/26 16:41:57 by zharzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pswap.h"

void	ft_move_pb(t_list **astack, t_list **bstack, t_control *val)
{
	t_list	*tmp1;

	if (*astack)
	{
		tmp1 = *astack;
		*astack = (*astack)->next;
		tmp1->next = *bstack;
		*bstack = tmp1;
		if (val->pop_a)
			val->pop_a--;
		else
			val->pop_ea--;
		val->pop_b++;
		val->total++;
		ft_printf("pb\n");
	}
}
