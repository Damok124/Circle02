/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack_check_order.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zharzi <zharzi@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/16 16:33:34 by zharzi            #+#    #+#             */
/*   Updated: 2022/08/16 20:50:52 by zharzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pswap.h"

int	ft_stack_check_order(t_list *stack, int pop, int order)
{
	if (!stack)
		return (0);
	while (stack && pop > 1)
	{
		if (ft_test_index(stack, stack->next) != order)
			return (0);
		stack = stack->next;
		pop--;
	}
	return (order);
}
