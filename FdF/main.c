/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zharzi <zharzi@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/31 13:40:17 by zharzi            #+#    #+#             */
/*   Updated: 2022/09/06 22:45:54 by zharzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

char	ft_base_key(int *tab, int key)
{
	int	i;
	int	x;

	i = 0;
	x = 0;
	while (i < 16)
	{
		if (key == tab[i])
			x = i;
		i++;
	}
	if (x < 10)
		return (x + '0');
	else
		x %= 10;
	return (x + 'A');
}

int	ft_manual_color(t_vars *vars, int key)
{
	static int	rank;
	char		code;

	code = ft_base_key((int []){65438, 65436, 65433, 65435, 65430, 65437, \
		65432, 65429, 65431, 65434, 97, 98, 99, 100, 101, 102}, key);
	vars->hexcolor[6] = '\0';
	vars->hexcolor[rank++ % 6] = code;
	ft_printf("hexcolor = %s\n", vars->hexcolor);
	return (1);
}

int	ft_renew_image(t_vars *vars)
{
	mlx_clear_window(vars->mlx, vars->win);
	mlx_destroy_image(vars->mlx, vars->img);
	vars->img = mlx_new_image(vars->mlx, WINDOW_WIDTH, WINDOW_HEIGHT);
	return (1);
}

int	ft_keypress(int key, t_vars *vars)
{
	if (key == 65307)
		mlx_loop_end(vars->mlx);
	else if (key == 99)
		ft_renew_image(vars);
	else if ((key >= 97 && key <= 102) || (key >= 65429 && key <= 65438))
		ft_manual_color(vars, key);
	ft_printf("key : %d\n", key);
	return (1);
}

int	ft_click_cross(t_vars *vars)
{
	mlx_loop_end(vars->mlx);
	return (0);
}

void	ft_end_mlx(t_vars *vars)
{
	mlx_destroy_image(vars->mlx, vars->img);
	mlx_destroy_window(vars->mlx, vars->win);
	mlx_destroy_display(vars->mlx);
	free(vars->hexcolor);
	free(vars->mlx);
	exit(0);
}

void	my_mlx_pixel_put(t_vars *vars, int x, int y, unsigned int color)
{
	char	*dst;

	dst = vars->addr + (y * vars->line_length + x * (vars->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

int	ft_dot(int button, int x, int y, t_vars *vars)
{
	(void)button;
	my_mlx_pixel_put(vars, x, y, vars->color);
	mlx_put_image_to_window(vars->mlx, vars->win, vars->img, 0, 0);
	return (0);
}

int	main(void)
{
	t_vars				vars;

	vars.mlx = mlx_init();
	if (!vars.mlx)
		return (MLX_ERROR);
	vars.win = mlx_new_window(vars.mlx, WINDOW_WIDTH, WINDOW_HEIGHT, "FDF");
	if (!vars.win)
	{
		free(vars.mlx);
		return (MLX_ERROR);
	}
	vars.hexcolor = (char *)malloc(sizeof(char) * 6 + 1);
	vars.hexcolor = ft_memset(vars.hexcolor, '0', 6);
	vars.hexcolor[6] = '\0';
	vars.color = 0x00FFFFFF;
	vars.img = mlx_new_image(vars.mlx, WINDOW_WIDTH, WINDOW_HEIGHT);
	vars.addr = mlx_get_data_addr(vars.img, &vars.bits_per_pixel, \
		&vars.line_length, &vars.endian);
	mlx_key_hook(vars.win, ft_keypress, &vars);
	mlx_mouse_hook(vars.win, ft_dot, &vars);
	mlx_hook(vars.win, ON_DESTROY, 2L<<0, ft_click_cross, &vars);
	mlx_loop(vars.mlx);
	ft_end_mlx(&vars);
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
