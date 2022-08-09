/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move_ra.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zharzi <zharzi@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/24 04:57:40 by zharzi            #+#    #+#             */
/*   Updated: 2022/08/07 19:29:18 by zharzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pswap.h"

void	ft_move_ra(t_list **astack)
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
		if (tmp1 && !(tmp1->next))
			tmp1->next = tmp2;
		ft_printf("ra\n");
	}
}
