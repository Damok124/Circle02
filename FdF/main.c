/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zharzi <zharzi@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/31 13:40:17 by zharzi            #+#    #+#             */
/*   Updated: 2022/09/19 22:42:56 by zharzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_print_grid(t_vars *vars, t_spot **matrix)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (j < vars->rows)
	{
		while (i < vars->len)
		{
			if (i != (vars->len -1) && j != (vars->rows - 1))
			{
				ft_link(vars, matrix[j][i], matrix[j][i + 1]);
				ft_link(vars, matrix[j][i], matrix[j + 1][i]);
			}
			else if (i == (vars->len - 1) && j != (vars->rows - 1))
				ft_link(vars, matrix[j][i], matrix[j + 1][i]);
			else if (i != (vars->len - 1) && j == (vars->rows - 1))
				ft_link(vars, matrix[j][i], matrix[j][i + 1]);
			i++;
		}
		i = 0;
		j++;
	}
}

void	ft_fdf_rotation(t_vars *vars, t_spot **matrix, int angle)
{
	int	i;
	int	j;

	(void)angle;
	i = 0;
	j = 0;
	while (j < vars->rows)
	{
		while (i < vars->len)
		{
			matrix[j][i].x *= 1;
			matrix[j][i].y *= 1;
			i++;
		}
		i = 0;
		j++;
	}
}

void	ft_fdf_vectorisation(t_vars *vars, t_spot **matrix, int direction)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (j < vars->rows)
	{
		while (i < vars->len)
		{
			matrix[j][i].x += vars->xmid * direction;
			matrix[j][i].y += vars->ymid * direction;
			i++;
		}
		i = 0;
		j++;
	}
}

void	ft_fdf_first_position(t_vars *vars, t_spot **matrix)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (j < vars->rows)//recalculer le spacing
	{
		while (i < vars->len)
		{
			matrix[j][i].x = (WINDOW_WIDTH / 2) + (vars->spacing * ((i + 1) - (vars->len - 1)));
			matrix[j][i].y = (WINDOW_HEIGHT / 2) + (vars->spacing * ((j + 1) - (vars->rows - 1)));
			i++;
		}
		i = 0;
		j++;
	}
}

void	ft_fdf_setup_matrix(t_vars *vars, t_spot **matrix)
{
	ft_fdf_first_position(vars, matrix);
	ft_print_grid(vars, matrix);
}

int	main(int ac, char **argv)
{
	t_vars	*vars;
	t_spot	**matrix;

	vars = ft_fdf_initvars(argv[ac - 1]);
	if (vars->len)
	{
		matrix = ft_map_to_matrix(vars, argv[ac - 1]);
		ft_fdf_setup_matrix(vars, matrix);
		mlx_key_hook(vars->win, ft_keypress, vars);
		mlx_hook(vars->win, ON_DESTROY, DestroyAll, ft_click_cross, vars);
		mlx_loop_hook(vars->mlx, ft_frame, vars);

		mlx_loop(vars->mlx);
		ft_fdf_free_matrix(matrix, vars);
		ft_end_mlx(&vars);
	}
	else
	{
		free(vars);
		ft_printf("Error\n");
		return (1);
	}
	return (0);
}

/*Votre programme doit afficher une image dans une fenêtre.

• La gestion de la fenêtre doit rester fluide (changer de fenêtre,
la réduire, etc.).

• Utiliser les images de la MiniLibX est obligatoire.*/

/*Ce projet consiste à créer graphiquement la représentation schématique
d’un terrain en relief en reliant différents points (x, y, z) par des segments.
Votre projet doit respecter les règles suivantes :
• Vous devez utiliser la MiniLibX. Soit la version disponible sur
les machines de l’école, soit en l’installant par les sources.

• Le rendu doit être affiché en utilisant une projection isométrique.

Chaque nombre représente un point dans l’espace :
• La position horizontale correspond à son abscisse.
• La position verticale correspond à son ordonnée.
• La valeur correspond à son altitude.
*/
