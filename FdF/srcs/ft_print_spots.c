/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_spots.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zharzi <zharzi@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 19:32:10 by zharzi            #+#    #+#             */
/*   Updated: 2022/09/22 19:50:40 by zharzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_print_spots(t_vars *vars, t_spot **matrix)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (j < vars->rows)
	{
		while (i < vars->len)
		{
			ft_print_dot(vars, matrix[j][i]);
			i++;
		}
		i = 0;
		j++;
	}
}
