/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_show_stacks.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zharzi <zharzi@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/11 11:21:36 by zharzi            #+#    #+#             */
/*   Updated: 2022/08/20 21:23:51 by zharzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pswap.h"

void	ft_show_masked(t_list **stack, t_control *values)
{
	t_list	*tmp;
	int		pop;

	pop = values->pop_a;
	tmp = *stack;
	while (pop)
	{
		tmp = tmp->next;
		pop--;
	}
	ft_show_lstindex(&tmp, values->lock);
}

void	ft_show_stacks(t_list **astack, t_list **bstack, t_control *val)
{
	t_list	*tmp;

	ft_printf("bstack : ");
	ft_show_lstindex(bstack, val->pop_b);
	if (val->pop_eb)
	{
		ft_printf("+&&&+");
		tmp = ft_first_estack(bstack, val->pop_b);
		ft_show_lstindex(&tmp, val->pop_eb);
	}
	ft_printf("\n");
	ft_printf("astack : ");
	ft_show_lstindex(astack, val->pop_a);
	if (val->lock)
	{
		ft_printf("+...+");
		ft_show_masked(astack, val);
	}
	if (val->pop_ea > 0)
	{
		ft_printf("+&&&+");
		tmp = ft_first_estack(astack, val->pop_a + val->lock);
		ft_show_lstindex(&tmp, val->pop_ea);
	}
	ft_printf("\n");
}
