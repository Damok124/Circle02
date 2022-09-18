/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_dot.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zharzi <zharzi@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/18 18:19:03 by zharzi            #+#    #+#             */
/*   Updated: 2022/09/18 18:19:43 by zharzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_print_dot(t_spot	dot)
{
	unsigned int	color;

	color = (dot.red << 16) + (dot.green << 8) + (dot.blue);
	ft_printf("y : %d; x : %d; z : %d\n", dot.y, dot.x, dot.z);
	ft_printf("color = %x\n", color);
}
