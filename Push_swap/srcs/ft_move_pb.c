/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move_pb.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zharzi <zharzi@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/24 04:57:31 by zharzi            #+#    #+#             */
/*   Updated: 2022/08/12 10:56:53 by zharzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pswap.h"

void	ft_move_pb(t_list **astack, t_list **bstack, t_control *values)
{
	t_list	*tmp1;

	if (*astack)
	{
		tmp1 = *astack;
		*astack = (*astack)->next;
		tmp1->next = *bstack;
		*bstack = tmp1;
		if (values->pop_a)
			values->pop_a--;
		else
			values->pop_ea--;
		values->pop_b++;
		ft_printf("pb\n");
	}
}
