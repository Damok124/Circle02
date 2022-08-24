/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move_rra.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zharzi <zharzi@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/24 04:58:13 by zharzi            #+#    #+#             */
/*   Updated: 2022/08/22 16:11:11 by zharzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pswap.h"

void	ft_rra_details(t_list **astack)
{
	t_list	*tmp1;
	t_list	*tmp2;

	if (*astack && (*astack)->next)
	{
		tmp2 = *astack;
		while (tmp2 && tmp2->next)
		{
			tmp1 = tmp2;
			tmp2 = tmp2->next;
		}
		tmp1->next = NULL;
		tmp2->next = *astack;
		*astack = tmp2;
	}
}

void	ft_move_rra(t_list **astack, t_control *val)
{
	if (*astack && (*astack)->next)
	{
		ft_rra_details(astack);
		if (val->pop_ea)
		{
			val->pop_a++;
			val->pop_ea--;
		}
		val->total++;
		ft_printf("rra\n");
	}
}
