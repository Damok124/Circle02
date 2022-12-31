/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move_rb.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zharzi <zharzi@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/31 11:58:22 by zharzi            #+#    #+#             */
/*   Updated: 2022/12/31 12:12:56 by zharzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pswap.h"

void	ft_move_rb(t_stack **bstack, int print)
{
	t_stack	*tmp1;
	t_stack	*tmp2;

	if (*bstack && (*bstack)->next)
	{
		tmp2 = *bstack;
		*bstack = (*bstack)->next;
		tmp2->next = NULL;
		tmp1 = *bstack;
		while (tmp1 && tmp1->next)
			tmp1 = tmp1->next;
		tmp1->next = tmp2;
		if (print)
			ft_printf("rb\n");
	}
}
