/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move_rrb.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zharzi <zharzi@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/24 04:59:58 by zharzi            #+#    #+#             */
/*   Updated: 2022/08/26 16:42:08 by zharzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pswap.h"

void	ft_rrb_details(t_list **bstack)
{
	t_list	*tmp1;
	t_list	*tmp2;

	if (*bstack && (*bstack)->next)
	{
		tmp2 = *bstack;
		while (tmp2 && tmp2->next)
		{
			tmp1 = tmp2;
			tmp2 = tmp2->next;
		}
		tmp1->next = NULL;
		tmp2->next = *bstack;
		*bstack = tmp2;
	}
}

void	ft_move_rrb(t_list **bstack, t_control *val)
{
	if (*bstack && (*bstack)->next)
	{
		ft_rrb_details(bstack);
		if (val->pop_eb)
		{
			val->pop_b++;
			val->pop_eb--;
		}
		val->total++;
		ft_printf("rrb\n");
	}
}
