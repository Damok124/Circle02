/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_manual_color.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zharzi <zharzi@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 17:52:14 by zharzi            #+#    #+#             */
/*   Updated: 2022/09/12 17:52:22 by zharzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	ft_manual_color(t_vars *vars, int key)
{
	static int	rank;
	char		code;
	int			check;

	check = 1;
	if ((key >= 97 && key <= 102) || (key >= 65429 && key <= 65438))
		code = ft_base_key((int []){65438, 65436, 65433, 65435, 65430, 65437, \
			65432, 65429, 65431, 65434, 97, 98, 99, 100, 101, 102}, key);
	else if ((key >= 48 && key <= 57))
		code = ft_base_key((int []){48, 49, 50, 51, 52, 53, 54, 55, 56, 57, 0, \
			0, 0, 0, 0, 0}, key);
	vars->hexcolor[rank++ % 6] = code;
	if (rank % 6 == 0)
	{
		ft_printf("actual hexcolor = %s\n", vars->hexcolor);
		vars->color = ft_atoi_base_safe(vars->hexcolor, &check, \
			"0123456789ABCDEF");
		vars->hexcolor = ft_memset(vars->hexcolor, '0', 6);
	}
	return (1);
}
