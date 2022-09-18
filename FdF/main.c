/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zharzi <zharzi@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/31 13:40:17 by zharzi            #+#    #+#             */
/*   Updated: 2022/09/18 18:54:43 by zharzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	main(int ac, char **argv)
{
	t_vars	*vars;
	t_spot	**matrix;

	vars = ft_fdf_initvars(argv[ac - 1]);
	if (vars->len)
	{
		matrix = ft_map_to_matrix(vars, argv[ac - 1]);
		mlx_key_hook(vars->win, ft_keypress, vars);
		mlx_hook(vars->win, ON_DESTROY, DestroyAll, ft_click_cross, vars);
		mlx_loop_hook(vars->mlx, ft_frame, vars);
		//mlx_loop(vars->mlx);
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
