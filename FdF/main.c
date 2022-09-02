/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zharzi <zharzi@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/31 13:40:17 by zharzi            #+#    #+#             */
/*   Updated: 2022/09/03 00:25:16 by zharzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, unsigned int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

int	main(int ac, char **argv)
{
	void			*target;
	void			*window;
	t_data			image;
	int				x;
	int				y;
	unsigned int	color;

	(void)ac;
	(void)argv;
	x = 10;
	y = 10;
	color = 0x00FF0000;
	target = mlx_init();
	if (!target)
		return (MLX_ERROR);
	window = mlx_new_window(target, WINDOW_WIDTH, WINDOW_HEIGHT, "FDF");
	if (!window)
	{
		free(target);
		return (MLX_ERROR);
	}
	image.img = mlx_new_image(target, WINDOW_WIDTH, WINDOW_HEIGHT);
	image.addr = mlx_get_data_addr(image.img, &image.bits_per_pixel, \
		&image.line_length, &image.endian);
	while (x <= 200)
	{
		my_mlx_pixel_put(&image, x, y, color);
		//color += 0x000001111;
		x++;
	}
	y++;
	x = 10;
	while (y < 200)
	{
		my_mlx_pixel_put(&image, x, y, color);
		//color += 0x000001111;
		while (x++ < 200)
		{
			my_mlx_pixel_put(&image, x, y, color + 0x00007FFF);
			//color += 0x000001111;
		}
		x = 10;
		my_mlx_pixel_put(&image, x * 20, y, color);
		//color += 0x000001111;
		y++;
	}
	while (x <= 200)
	{
		my_mlx_pixel_put(&image, x, y, color);
		//color += 0x000001111;
		x++;
	}
	mlx_put_image_to_window(target, window, image.img, 0, 0);
	mlx_loop(target);
	mlx_destroy_window(target, window);
	mlx_destroy_display(target);
	free(target);
	return (0);
}
/*
int	main(int ac, char **argv)
{
	int		fd;
	char	*str;
	void	*mlx;
	void	*mlx_win;

	(void)ac;
	fd = open(argv[1], O_RDONLY);
	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 800, 600, "Fdf");
	mlx_loop(mlx);
	(void)mlx_win;
	str = get_next_line(fd);
	while (str)
	{
		ft_printf("%s", str);
		free(str);
		str = get_next_line(fd);
	}
	mlx_destroy_window(mlx, mlx_win);
	mlx_destroy_display(mlx);
	close(fd);
	return (0);
}*/
/*Votre programme doit afficher une image dans une fenêtre.
• La gestion de la fenêtre doit rester fluide (changer de fenêtre,
la réduire, etc.).
• Appuyer sur la touche ESC doit fermer la fenêtre et quitter le programme
proprement.
• Cliquer sur la croix en haut de la fenêtre doit fermer celle-ci et quitter
le programme proprement.
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
