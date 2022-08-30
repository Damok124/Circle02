/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fill_controlval.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zharzi <zharzi@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/11 08:01:03 by zharzi            #+#    #+#             */
/*   Updated: 2022/08/27 07:53:16 by zharzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pswap.h"

t_control	ft_fill_controlval(int ac)
{
	t_control	values;

	values.ac = ac;
	values.min = 0;
	values.max = ac - 1;
	values.firstthird = (ac - 1) / 3;
	values.lastthird = (ac - 1) * 2 / 3;
	values.pop_a = ac;
	values.lock = 0;
	values.pop_ea = 0;
	values.pop_b = 0;
	values.pop_eb = 0;
	return (values);
}
