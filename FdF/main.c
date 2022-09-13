/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zharzi <zharzi@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/31 13:40:17 by zharzi            #+#    #+#             */
/*   Updated: 2022/09/13 23:51:33 by zharzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	ft_frame(t_vars	*vars)
{
	if (vars->addr)
		mlx_put_image_to_window(vars->mlx, vars->win, vars->img, 0, 0);
	return (1);
}

int	ft_get_octant(int x1, int x2, int y1, int y2)
{
	int	dx;
	int	dy;
	int	octant;

	dx = x2 - x1;
	dy = y2 - y1;
	if (dx >= 0 && dy >= 0)
	{
		if (dx >= dy)
			octant = 8;
		else
			octant = 7;
	}
	else if (dx <= 0 && dy >= 0)
	{
		if (-dx >= dy)
			octant = 5;
		else
			octant = 6;
	}
	else if (dx < 0 && dy < 0)
	{
		if (-dx >= -dy)
			octant = 4;
		else
			octant = 3;
	}
	else if (dx > 0 && dy < 0)
	{
		if (dx >= -dy)
			octant = 1;
		else
			octant = 2;
	}
	return (octant);
}

void	ft_trace_oct8(t_vars *vars, t_spot *a, t_spot *b)
{
	int	dx;
	int	dy;
	int	x;
	int	y;
	int	eps;

	dx = b->x - a->x;
	dy = b->y - a->y;
	x = a->x;
	y = a->y;
	eps = 0;

	while (x <= b->x)
	{
		ft_pixel_put(vars, x, y, vars->color);
		eps += dy;
		if (eps * 2 >= dx)
		{
			y++;
			eps -= dx;
		}
		x++;
	}
}

void	ft_trace_oct7(t_vars *vars, t_spot *a, t_spot *b)
{
	int	dx;
	int	dy;
	int	x;
	int	y;
	int	eps;

	dx = b->x - a->x;
	dy = b->y - a->y;
	x = a->x;
	y = a->y;
	eps = 0;

	while (y <= b->y)
	{
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

void	ft_trace_oct6(t_vars *vars, t_spot *a, t_spot *b)
{
	int	dx;
	int	dy;
	int	x;
	int	y;
	int	eps;

	dx = b->x - a->x;
	dy = (b->y - a->y) * -1;
	x = a->x;
	y = a->y;
	eps = 0;

	while (y <= b->y)
	{
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

void	ft_trace_oct5(t_vars *vars, t_spot *a, t_spot *b)
{
	int	dx;
	int	dy;
	int	x;
	int	y;
	int	eps;

	dx = b->x - a->x;
	dy = (b->y - a->y) * -1;
	x = a->x;
	y = a->y;
	eps = 0;

	while (x >= b->x)
	{
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

void	ft_trace_oct4(t_vars *vars, t_spot *a, t_spot *b)
{
	int	dx;
	int	dy;
	int	x;
	int	y;
	int	eps;

	dx = b->x - a->x;
	dy = b->y - a->y;
	x = a->x;
	y = a->y;
	eps = 0;

	while (x <= b->x)
	{
		ft_pixel_put(vars, x, y, vars->color);
		eps += dy;
		if (eps * 2 >= dx)
		{
			y++;
			eps -= dx;
		}
		x++;
	}
}

void	ft_trace_oct3(t_vars *vars, t_spot *a, t_spot *b)
{
	int	dx;
	int	dy;
	int	x;
	int	y;
	int	eps;

	dx = b->x - a->x;
	dy = b->y - a->y;
	x = a->x;
	y = a->y;
	eps = 0;

	while (x <= b->x)
	{
		ft_pixel_put(vars, x, y, vars->color);
		eps += dy;
		if (eps * 2 >= dx)
		{
			y++;
			eps -= dx;
		}
		x++;
	}
}

void	ft_trace_oct2(t_vars *vars, t_spot *a, t_spot *b)
{
	int	dx;
	int	dy;
	int	x;
	int	y;
	int	eps;

	dx = b->x - a->x;
	dy = b->y - a->y;
	x = a->x;
	y = a->y;
	eps = 0;

	while (x <= b->x)
	{
		ft_pixel_put(vars, x, y, vars->color);
		eps += dy;
		if (eps * 2 >= dx)
		{
			y++;
			eps -= dx;
		}
		x++;
	}
}

void	ft_trace_oct1(t_vars *vars, t_spot *a, t_spot *b)
{
	int	dx;
	int	dy;
	int	x;
	int	y;
	int	eps;

	dx = b->x - a->x;
	dy = b->y - a->y;
	x = a->x;
	y = a->y;
	eps = 0;

	while (x <= b->x)
	{
		ft_pixel_put(vars, x, y, vars->color);
		eps += dy;
		if (eps * 2 >= dx)
		{
			y++;
			eps -= dx;
		}
		x++;
	}
}
//mettre en place les octants mirroirs
int	ft_link(t_vars *vars, t_spot *a, t_spot *b)
{
	int	x1;
	int	x2;
	int	y1;
	int	y2;
	int	octant;

	x1 = a->x;
	x2 = b->x;
	y1 = a->y;
	y2 = b->y;
	octant = 0;
	ft_pixel_put(vars, x1, y1, vars->color);
	ft_pixel_put(vars, x2, y2, vars->color);
	octant = ft_get_octant(x1, x2, y1, y2);
	ft_printf("octant actuel : %d\n", octant);
	if (octant == 8)
		ft_trace_oct8(vars, a, b);
	if (octant == 7)
		ft_trace_oct7(vars, a, b);
	if (octant == 6)
		ft_trace_oct6(vars, a, b);
	if (octant == 5)
		ft_trace_oct5(vars, a, b);
	if (octant == 4)
		ft_trace_oct4(vars, a, b);
	if (octant == 3)
		ft_trace_oct3(vars, a, b);
	if (octant == 2)
		ft_trace_oct2(vars, a, b);
	if (octant == 1)
		ft_trace_oct1(vars, a, b);
	return (1);
}

int	main(void)
{
	t_vars				vars;
	t_spot				a;
	t_spot				b;

	a.x = 300;
	a.y = 300;
	a.z = 0;
	b.x = 150;
	b.y = 450;
	b.z = 0;
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
	//mlx_mouse_hook(vars.win, ft_dot, &vars);
	mlx_hook(vars.win, ON_DESTROY, DestroyAll, ft_click_cross, &vars);
	mlx_loop_hook(vars.mlx, ft_frame, &vars);
	ft_link(&vars, &a, &b);
	mlx_loop(vars.mlx);
	ft_end_mlx(&vars);
	return (0);
}

/*Votre programme doit afficher une image dans une fenêtre.
(faut-il utiliser le mlx loop hook?)
https://aurelienbrabant.fr/blog/pixel-drawing-with-the-minilibx

https://aurelienbrabant.fr/blog/managing-events-with-the-minilibx

L'evenement expose retrace ce qu'il y a dans la fenetre

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
