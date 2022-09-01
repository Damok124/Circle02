/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zharzi <zharzi@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/31 13:40:17 by zharzi            #+#    #+#             */
/*   Updated: 2022/09/01 19:22:33 by zharzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

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
}

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
