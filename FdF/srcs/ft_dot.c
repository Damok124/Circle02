/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dot.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zharzi <zharzi@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 18:01:59 by zharzi            #+#    #+#             */
/*   Updated: 2022/09/13 17:45:44 by zharzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	ft_dot(int button, int x, int y, t_vars *vars)
{
	(void)button;
	ft_pixel_put(vars, x, y, vars->color);
	//mlx_put_image_to_window(vars->mlx, vars->win, vars->img, 0, 0);
	return (0);
}
