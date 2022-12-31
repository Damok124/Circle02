/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_down_cost.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zharzi <zharzi@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/31 11:58:22 by zharzi            #+#    #+#             */
/*   Updated: 2022/12/31 12:35:17 by zharzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pswap.h"

int	ft_down_cost(t_stack **stack, int target)
{
	t_stack	*lst;
	int		i;

	i = 0;
	lst = *stack;
	while (lst && lst->index != target)
		lst = lst->next;
	if (!lst)
		return (INT_MAX);
	if (lst->index == target)
		lst = lst->next;
	while (lst && lst->index != target)
	{
		i++;
		lst = lst->next;
	}
	return (i);
}
