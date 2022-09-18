/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fdf_spacing.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zharzi <zharzi@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/18 18:49:39 by zharzi            #+#    #+#             */
/*   Updated: 2022/09/18 18:49:49 by zharzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	ft_fdf_spacing(t_vars *vars)
{
	int	ratio;

	if (vars->len == 1 && vars->rows > 1)
		return ((WINDOW_HEIGHT * 90 / 100) / (vars->rows - 1));
	else if (vars->rows == 1 && vars->len > 1)
		return ((WINDOW_WIDTH * 80 / 100) / (vars->len - 1));
	else if (vars->len == 1 && vars->rows == 1)
		return (0);
	ratio = (WINDOW_HEIGHT * 90 / 100) / (vars->rows - 1);
	if (ratio > (WINDOW_WIDTH * 80 / 100) / (vars->len - 1))
		ratio = (WINDOW_WIDTH * 80 / 100) / (vars->len - 1);
	return (ratio);
}
