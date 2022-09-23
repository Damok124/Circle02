/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dot.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zharzi <zharzi@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 18:01:59 by zharzi            #+#    #+#             */
/*   Updated: 2022/09/21 14:59:50 by zharzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	ft_dot(int button, int x, int y, t_vars *vars)
{
	(void)button;
	ft_pixel_put(vars, x, y);
	return (0);
}
