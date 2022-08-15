/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_show_stacks.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zharzi <zharzi@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/11 11:21:36 by zharzi            #+#    #+#             */
/*   Updated: 2022/08/15 17:50:48 by zharzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pswap.h"

void	ft_show_stacks(t_list **astack, t_list **bstack, t_control *val)
{
	t_list	*tmp;

	ft_printf("bstack : ");
	ft_show_lstint(bstack, val->pop_b);
	if (val->pop_eb)
	{
		ft_printf("+&&&+");
		tmp = ft_first_estack(bstack, val->pop_b);
		ft_show_lstint(&tmp, val->pop_eb);
	}
	ft_printf("\n");
	ft_printf("astack : ");
	ft_show_lstint(astack, val->pop_a);
	if (val->pop_ea)
	{
		ft_printf("+&&&+");
		tmp = ft_first_estack(astack, val->pop_a);
		ft_show_lstint(&tmp, val->pop_ea);
	}
	ft_printf("\n");
}
