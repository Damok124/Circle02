/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_show_values.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zharzi <zharzi@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/11 11:18:34 by zharzi            #+#    #+#             */
/*   Updated: 2022/08/23 21:38:13 by zharzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pswap.h"

void	ft_show_values(t_control values)
{
	ft_printf("ac %d\t", values.ac);
	ft_printf("min[%d ", values.min);
	ft_printf("to %d]max\n", values.max);
	ft_printf("1/3 at %d\t", values.firstthird);
	ft_printf("2/3 at %d\n\n", values.lastthird);
	ft_printf("pop  a %d\t", values.pop_a);
	ft_printf("pop  b %d\n", values.pop_b);
	ft_printf("lock a %d\t", values.lock);
	ft_printf("total  %d\n", values.total);
	ft_printf("pop ea %d\t", values.pop_ea);
	ft_printf("pop eb %d\n\n", values.pop_eb);
}
