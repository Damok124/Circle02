/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move_sb.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zharzi <zharzi@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/24 05:00:25 by zharzi            #+#    #+#             */
/*   Updated: 2022/08/22 15:56:08 by zharzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pswap.h"

void	ft_move_sb(t_list **bstack, t_control *val)
{
	t_list	*elem3;
	t_list	*elem2;

	if (*bstack && (*bstack)->next)
	{
		elem3 = (*bstack)->next;
		elem2 = elem3;
		elem3 = elem3->next;
		elem2->next = *bstack;
		(*bstack)->next = elem3;
		*bstack = elem2;
		val->total++;
		ft_printf("sb\n");
	}
}
