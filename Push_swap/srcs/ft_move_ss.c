/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move_ss.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zharzi <zharzi@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/24 05:00:32 by zharzi            #+#    #+#             */
/*   Updated: 2022/08/07 01:21:57 by zharzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pswap.h"

void	ft_move_ss(t_list **astack, t_list **bstack)
{
	t_list	*elem3;
	t_list	*elem2;

	if (*astack && (*astack)->next && *bstack && (*bstack)->next)
	{
		elem3 = (*astack)->next;
		elem2 = elem3;
		elem3 = elem3->next;
		elem2->next = *astack;
		(*astack)->next = elem3;
		*astack = elem2;
		elem3 = (*bstack)->next;
		elem2 = elem3;
		elem3 = elem3->next;
		elem2->next = *bstack;
		(*bstack)->next = elem3;
		*bstack = elem2;
		ft_printf("ss\n");
	}
}
