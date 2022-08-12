/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fill_controlval.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zharzi <zharzi@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/11 08:01:03 by zharzi            #+#    #+#             */
/*   Updated: 2022/08/12 09:01:09 by zharzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pswap.h"

t_control	ft_fill_controlval(int ac, t_list **astack)
{
	t_list		*tmp;
	t_control	values;

	values.ac = ac;
	values.min = INT_MAX;
	values.max = INT_MIN;
	tmp = *astack;
	while (tmp)
	{
		ft_printf("content %d, index %d\n", *(int *)tmp->content, tmp->index);
		if (values.min > *(int *)tmp->content)
			values.min = *(int *)tmp->content;
		if (values.max < *(int *)tmp->content)
			values.max = *(int *)tmp->content;
		tmp = tmp->next;
	}
	values.firstthird = (ac + 1) / 3;
	values.lastthird = (ac + 1) * 2 / 3;
	values.pop_a = ac;
	values.pop_b = 0;
	values.pop_ea = 0;
	values.pop_eb = 0;
	return (values);
}
