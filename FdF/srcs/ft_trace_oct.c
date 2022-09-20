/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_trace_oct.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zharzi <zharzi@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 13:23:29 by zharzi            #+#    #+#             */
/*   Updated: 2022/09/20 16:30:05 by zharzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

unsigned int	ft_get_color(t_spot a, t_spot b, int x, int y)
{
	int r;
	int g;
	int b;

	b.red - a.red
}

void	ft_trace_oct8(t_vars *vars, t_spot a, t_spot b)
{
	unsigned int	color;
	int	x;
	int	y;
	int	eps;

	x = a.x;
	y = a.y;
	eps = 0;
	while (x <= b.x)
	{
		if (ft_pix_is_visible(x, y))
		{
			color = ft_get_color(a, b, x, y);
			ft_pixel_put(vars, x, y, vars->color);//
		}
		eps += (b.y - a.y);
		if (eps * 2 >= (b.x - a.x))
		{
			y++;
			eps -= (b.x - a.x);
		}
		x++;
	}
}

void	ft_trace_oct7(t_vars *vars, t_spot a, t_spot b)
{
	int	dx;
	int	dy;
	int	x;
	int	y;
	int	eps;

	dx = b.x - a.x;
	dy = b.y - a.y;
	x = a.x;
	y = a.y;
	eps = 0;
	while (y <= b.y)
	{
		if (ft_pix_is_visible(x, y))
			ft_pixel_put(vars, x, y, vars->color);
		eps += dx;
		if (eps * 2 >= dy)
		{
			x++;
			eps -= dy;
		}
		y++;
	}
}

void	ft_trace_oct6(t_vars *vars, t_spot a, t_spot b)
{
	int	dx;
	int	dy;
	int	x;
	int	y;
	int	eps;

	dx = b.x - a.x;
	dy = (b.y - a.y) * -1;
	x = a.x;
	y = a.y;
	eps = 0;
	while (y <= b.y)
	{
		if (ft_pix_is_visible(x, y))
			ft_pixel_put(vars, x, y, vars->color);
		eps += dx;
		if (eps * 2 <= dy)
		{
			x--;
			eps -= dy;
		}
		y++;
	}
}

void	ft_trace_oct5(t_vars *vars, t_spot a, t_spot b)
{
	int	dx;
	int	dy;
	int	x;
	int	y;
	int	eps;

	dx = b.x - a.x;
	dy = (b.y - a.y) * -1;
	x = a.x;
	y = a.y;
	eps = 0;
	while (x >= b.x)
	{
		if (ft_pix_is_visible(x, y))
			ft_pixel_put(vars, x, y, vars->color);
		eps += dy;
		if (eps * 2 <= dx)
		{
			y++;
			eps -= dx;
		}
		x--;
	}
}
