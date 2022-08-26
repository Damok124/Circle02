/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move_rb.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zharzi <zharzi@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/24 04:57:54 by zharzi            #+#    #+#             */
/*   Updated: 2022/08/26 16:42:01 by zharzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pswap.h"

void	ft_rb_details(t_list **bstack)
{
	t_list	*tmp1;
	t_list	*tmp2;

	if (*bstack && (*bstack)->next)
	{
		tmp2 = *bstack;
		*bstack = (*bstack)->next;
		tmp2->next = NULL;
		tmp1 = *bstack;
		while (tmp1 && tmp1->next)
			tmp1 = tmp1->next;
		tmp1->next = tmp2;
	}
}

void	ft_move_rb(t_list **bstack, t_control *val)
{
	if (*bstack && (*bstack)->next)
		ft_rb_details(bstack);
	if (val->pop_b)
	{
		val->pop_b--;
		val->pop_eb++;
		val->total++;
	}
	ft_printf("rb\n");
}
