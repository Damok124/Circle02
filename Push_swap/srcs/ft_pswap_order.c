/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pswap_order.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zharzi <zharzi@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 14:03:43 by zharzi            #+#    #+#             */
/*   Updated: 2022/08/15 14:03:47 by zharzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pswap.h"

int	ft_pswap_order(t_list **stack, int pop)
{
	t_list	*tmp;
	int		order;

	tmp = *stack;
	order = 0;
	if (pop == 1)
		return (2);
	if (pop > 1)
	{
		if (tmp->index + 1 == tmp->next->index)
			order = 1;
		else if (tmp->index - 1 == tmp->next->index)
			order = -1;
	}
	while (pop > 1 && order)
	{
		if (tmp->index + order != tmp->next->index)
			order = 0;
		tmp = tmp->next;
		pop--;
	}
	return (order);
}
