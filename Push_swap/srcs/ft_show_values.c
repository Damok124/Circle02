/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_show_values.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zharzi <zharzi@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/11 11:18:34 by zharzi            #+#    #+#             */
/*   Updated: 2022/08/11 11:20:26 by zharzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pswap.h"

void	ft_show_values(t_control values)
{
	ft_printf("ac %d\tmin[%d to %d]max\n", values.ac, values.min, values.max);
	ft_printf("1/3 at %d\t2/3 at %d\n", values.firstthird, values.lastthird);
	ft_printf("pop  a %d\tpop  b %d\n", values.pop_a, values.pop_b);
	ft_printf("pop ea %d\tpop eb %d\n", values.pop_ea, values.pop_eb);
}
