/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zharzi <zharzi@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/31 13:40:17 by zharzi            #+#    #+#             */
/*   Updated: 2022/09/25 23:23:46 by zharzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_fdf_setup_matrix(t_vars *vars, t_spot **matrix)
{
	ft_fdf_first_position(vars, matrix);
	ft_fdf_rotation_z(vars, matrix, 3.14159265 * 45 / 180);
	ft_fdf_rotation_x(vars, matrix, 3.14159265 * 60 / 180);
	ft_fdf_last_position(vars, matrix);
	ft_print_grid(vars, matrix);
}

void	ft_fdf(char *filename)
{
	t_vars	*vars;
	t_spot	**matrix;

	vars = ft_fdf_initvars(filename);
	if (!vars)
	{
		ft_printf("Error. Check your map.\n");
		return ;
	}
	matrix = ft_map_to_matrix(vars, filename);
	mlx_key_hook(vars->win, ft_keypress, vars);
	mlx_hook(vars->win, ON_DESTROY, DestroyAll, ft_click_cross, vars);
	mlx_loop_hook(vars->mlx, ft_frame, vars);
	ft_fdf_setup_matrix(vars, matrix);
	mlx_loop(vars->mlx);
	ft_fdf_free_matrix(matrix, vars);
	ft_end_mlx(&vars);
}

int	ft_fdf_error_management(int ac, char **argv)
{
	int	fd;

	if (ac != 2)
		return (1);
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
		return (2);
	close(fd);
	return (0);
}

int	main(int ac, char **argv)
{
	int	error;

	error = ft_fdf_error_management(ac, argv);
	if (!error)
		ft_fdf(argv[ac - 1]);
	else
	{
		ft_printf("Error. Wrong argument(s).\n");
	}
	return (0);
}
