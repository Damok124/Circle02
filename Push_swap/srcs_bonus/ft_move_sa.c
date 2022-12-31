/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move_sa.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zharzi <zharzi@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/31 11:58:22 by zharzi            #+#    #+#             */
/*   Updated: 2022/12/31 15:31:54 by zharzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pswap_bonus.h"

void	ft_move_sa(t_stack **astack, int print)
{
	t_stack	*elem3;
	t_stack	*elem2;

	if (*astack && (*astack)->next)
	{
		elem3 = (*astack)->next;
		elem2 = elem3;
		elem3 = elem3->next;
		elem2->next = *astack;
		(*astack)->next = elem3;
		*astack = elem2;
		if (print)
			ft_printf("sa\n");
	}
}
