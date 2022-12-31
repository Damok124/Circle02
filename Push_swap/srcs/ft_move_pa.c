/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move_pa.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zharzi <zharzi@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/31 11:58:22 by zharzi            #+#    #+#             */
/*   Updated: 2022/12/31 12:11:38 by zharzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pswap.h"

void	ft_move_pa(t_stack **astack, t_stack **bstack, int print)
{
	t_stack	*tmp1;

	if (*bstack)
	{
		tmp1 = *bstack;
		*bstack = (*bstack)->next;
		tmp1->next = *astack;
		*astack = tmp1;
		if (print)
			ft_printf("pa\n");
	}
}
