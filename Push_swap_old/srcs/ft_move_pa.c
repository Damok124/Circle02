/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move_pa.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zharzi <zharzi@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/24 04:57:16 by zharzi            #+#    #+#             */
/*   Updated: 2022/08/26 16:41:56 by zharzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pswap.h"

void	ft_move_pa(t_list **astack, t_list **bstack, t_control *val)
{
	t_list	*tmp1;

	if (*bstack)
	{
		tmp1 = *bstack;
		*bstack = (*bstack)->next;
		tmp1->next = *astack;
		*astack = tmp1;
		if (val->pop_b)
			val->pop_b--;
		else
			val->pop_eb--;
		val->pop_a++;
		val->total++;
		ft_printf("pa\n");
	}
}
