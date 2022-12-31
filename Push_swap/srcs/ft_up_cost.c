/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_up_cost.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zharzi <zharzi@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/31 12:34:52 by zharzi            #+#    #+#             */
/*   Updated: 2022/12/31 12:34:55 by zharzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pswap.h"

int	ft_up_cost(t_stack **stack, int target)
{
	t_stack	*lst;
	int		i;

	i = 0;
	lst = *stack;
	while (lst)
	{
		if (lst->index != target)
		{
			i++;
			lst = lst->next;
		}
		else
			lst = NULL;
	}
	return (i);
}
