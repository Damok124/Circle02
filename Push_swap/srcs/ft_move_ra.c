/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move_ra.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zharzi <zharzi@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/24 04:57:40 by zharzi            #+#    #+#             */
/*   Updated: 2022/08/15 16:36:41 by zharzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pswap.h"

void	ft_ra_details(t_list **astack)
{
	t_list	*tmp1;
	t_list	*tmp2;

	if (*astack && (*astack)->next)
	{
		tmp2 = *astack;
		*astack = (*astack)->next;
		tmp2->next = NULL;
		tmp1 = *astack;
		while (tmp1 && tmp1->next)
			tmp1 = tmp1->next;
		tmp1->next = tmp2;
	}
}

void	ft_move_ra(t_list **astack, t_control *values)
{
	if (*astack && (*astack)->next)
		ft_ra_details(astack);
	if (values->pop_a)
	{
		values->pop_a--;
		values->pop_ea++;
	}
	ft_printf("ra\n");
}
