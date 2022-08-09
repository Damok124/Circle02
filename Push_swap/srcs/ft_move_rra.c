/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move_rra.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zharzi <zharzi@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/24 04:58:13 by zharzi            #+#    #+#             */
/*   Updated: 2022/08/07 21:14:01 by zharzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pswap.h"

void	ft_move_rra(t_list **astack)
{
	t_list	*tmp1;
	t_list	*tmp2;

	if (*astack && (*astack)->next)
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
		ft_printf("rra\n");
	}
}
