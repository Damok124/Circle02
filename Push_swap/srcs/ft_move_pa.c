/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move_pa.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zharzi <zharzi@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/24 04:57:16 by zharzi            #+#    #+#             */
/*   Updated: 2022/08/12 10:57:29 by zharzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pswap.h"

void	ft_move_pa(t_list **astack, t_list **bstack, t_control *values)
{
	t_list	*tmp1;

	if (*bstack)
	{
		tmp1 = *bstack;
		*bstack = (*bstack)->next;
		tmp1->next = *astack;
		*astack = tmp1;
		if (values->pop_b)
			values->pop_b--;
		else
			values->pop_eb--;
		values->pop_a++;
		ft_printf("pa\n");
	}
}
