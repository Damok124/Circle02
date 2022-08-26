/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_order_all.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zharzi <zharzi@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/17 21:58:13 by zharzi            #+#    #+#             */
/*   Updated: 2022/08/26 16:00:49 by zharzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pswap.h"

int	ft_check_order_a(t_list	*astack, t_control *val)
{
	if (ft_stack_check_order(astack, val->pop_a, -1) == -1)
		return (1);
	else
		return (0);
}

int	ft_check_order_ea(t_list *astack, t_control *val)
{
	t_list	*tmp;

	tmp = ft_first_estack(&astack, val->pop_a + val->lock);
	if (ft_stack_check_order(tmp, val->pop_ea, 1) == 1)
		return (1);
	else
		return (0);
}

int	ft_check_order_b(t_list	**bstack, t_control *val)
{
	if (ft_stack_check_order(*bstack, val->pop_b, 1) == 1)
		return (1);
	else
		return (0);
}

int	ft_check_order_eb(t_list **bstack, t_control *val)
{
	t_list	*tmp;

	tmp = ft_first_estack(bstack, val->pop_b);
	if (ft_stack_check_order(tmp, val->pop_eb, 1) == 1)
		return (1);
	else
		return (0);
}
