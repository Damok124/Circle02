/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dot.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zharzi <zharzi@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 18:01:59 by zharzi            #+#    #+#             */
/*   Updated: 2022/09/19 18:27:25 by zharzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	ft_dot(int button, int x, int y, t_vars *vars)
{
	(void)button;
	ft_pixel_put(vars, x, y, vars->color);
	return (0);
}
