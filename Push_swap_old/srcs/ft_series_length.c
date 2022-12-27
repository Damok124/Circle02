/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_series_length.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zharzi <zharzi@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/24 15:41:27 by zharzi            #+#    #+#             */
/*   Updated: 2022/08/26 16:42:19 by zharzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pswap.h"

int	ft_series_length(t_list *stack, int order, int position)
{
	int	length;

	length = 0;
	while (stack && --position)
		stack = stack->next;
	if (!stack)
		return (length);
	else
		length++;
	while (stack->next && ft_test_index(stack, stack->next) == order)
	{
		stack = stack->next;
		length++;
	}
	return (length);
}
