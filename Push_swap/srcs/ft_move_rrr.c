/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move_rrr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zharzi <zharzi@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/24 05:00:08 by zharzi            #+#    #+#             */
/*   Updated: 2022/08/07 21:13:46 by zharzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pswap.h"

void	ft_move_rrr(t_list **astack, t_list **bstack)
{
	t_list	*tmp1;
	t_list	*tmp2;

	if (*astack && (*astack)->next && *bstack && (*bstack)->next)
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
		tmp2 = *bstack;
		while (tmp2 && tmp2->next)
		{
			tmp1 = tmp2;
			tmp2 = tmp2->next;
		}
		tmp1->next = NULL;
		tmp2->next = *bstack;
		*bstack = tmp2;
		ft_printf("rrr\n");
	}
}
