/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fdf_initvars.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zharzi <zharzi@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/18 18:51:46 by zharzi            #+#    #+#             */
/*   Updated: 2022/09/18 18:53:44 by zharzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_vars	*ft_fdf_initvars(char *filename)
{
	t_vars	*vars;

	vars = (t_vars *)malloc(sizeof(t_vars));
	vars->mlx = mlx_init();
	if (!vars->mlx)
		return (NULL);
	vars->win = mlx_new_window(vars->mlx, WINDOW_WIDTH, WINDOW_HEIGHT, "FDF");
	if (!vars->win)
	{
		free(vars->mlx);
		return (NULL);
	}
	vars->hexcolor = ft_fdf_initcol();
	vars->color = ft_btou(vars->hexcolor + 2, "0123456789ABCDEF");
	vars->img = mlx_new_image(vars->mlx, WINDOW_WIDTH, WINDOW_HEIGHT);
	vars->addr = mlx_get_data_addr(vars->img, &vars->bits_per_pixel, \
		&vars->line_length, &vars->endian);
	vars->rows = ft_fdf_rowcount(filename);
	ft_fdf_lencheck(vars, filename);
	vars->spacing = ft_fdf_spacing(vars);
	return (vars);
}
