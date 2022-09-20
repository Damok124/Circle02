/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fdf_get_center.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zharzi <zharzi@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 18:42:43 by zharzi            #+#    #+#             */
/*   Updated: 2022/09/19 22:08:09 by zharzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_get_center(t_vars *vars)
{
	int	xlast;
	int	xfirst;
	int	ylast;
	int	yfirst;

	xlast = ((vars->len - 1) * vars->spacing) + (WINDOW_WIDTH * 20 / 100 / 2);
	xfirst = (WINDOW_WIDTH * 20 / 100 / 2);
	vars->xmid = (xlast - xfirst) / 2 + (WINDOW_WIDTH * 20 / 100 / 2);
	ylast = ((vars->rows - 1) * vars->spacing) + (WINDOW_HEIGHT * 10 / 100 / 2);
	yfirst = (WINDOW_HEIGHT * 10 / 100 / 2);
	vars->ymid = (ylast - yfirst) / 2 + (WINDOW_HEIGHT * 10 / 100 / 2);
}
