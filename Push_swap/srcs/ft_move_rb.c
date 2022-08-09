/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move_rb.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zharzi <zharzi@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/24 04:57:54 by zharzi            #+#    #+#             */
/*   Updated: 2022/08/07 19:29:16 by zharzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pswap.h"

void	ft_move_rb(t_list **bstack)
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
		if (tmp1 && !(tmp1->next))
			tmp1->next = tmp2;
		ft_printf("rb\n");
	}
}
