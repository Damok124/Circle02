/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_matrix.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zharzi <zharzi@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/18 18:19:05 by zharzi            #+#    #+#             */
/*   Updated: 2022/09/18 18:19:24 by zharzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_print_matrix(t_spot **matrix, t_vars *vars)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (y < vars->rows)
	{
		while (x < vars->len)
		{
			ft_print_dot(matrix[y][x]);
			x++;
		}
		x = 0;
		y++;
	}
}
