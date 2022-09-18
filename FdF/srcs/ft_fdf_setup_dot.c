/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fdf_setup_dot.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zharzi <zharzi@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/18 18:13:39 by zharzi            #+#    #+#             */
/*   Updated: 2022/09/18 18:14:24 by zharzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_spot	ft_fdf_setup_dot(char *buffer, int x, int y, t_vars *vars)
{
	t_spot			dot;
	char			**sequence;
	char			*color;
	unsigned int	col;

	dot.x = x;
	dot.y = y;
	sequence = ft_split(buffer, ' ');
	dot.z = ft_atoi(sequence[x]);
	if (ft_strchr(sequence[x], ','))
		color = ft_strchr(sequence[x], 'x') + 1;
	else
		color = vars->hexcolor + 2;
	col = ft_btou(color, "0123456789ABCDEF");
	dot.blue = col & 0xFF;
	dot.green = (col >> 8) & 0xFF;
	dot.red = (col >> 16) & 0xFF;
	ft_full_free((void **)sequence);
	return (dot);
}
