/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fill_controlval.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zharzi <zharzi@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/11 08:01:03 by zharzi            #+#    #+#             */
/*   Updated: 2022/08/23 21:35:28 by zharzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pswap.h"

t_control	ft_fill_controlval(int ac)
{
	t_control	values;

	if (ac)
	{
		values.ac = ac;
		values.min = 1;
		values.max = ac;
		values.firstthird = ac / 3;
		values.lastthird = ac * 2 / 3;
		values.pop_a = ac;
		values.lock = 0;
		values.pop_ea = 0;
		values.pop_b = 0;
		values.pop_eb = 0;
		values.total = 0;
	}
	return (values);
}
