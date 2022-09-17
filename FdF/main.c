/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zharzi <zharzi@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/31 13:40:17 by zharzi            #+#    #+#             */
/*   Updated: 2022/09/17 23:49:30 by zharzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

char	*ft_fdf_buffertrim(char *buffer)
{
	char	*tmp;

	tmp = ft_strtrim(buffer, "\n");
	ft_true_free(&buffer);
	buffer = ft_strtrim(tmp, " ");
	ft_true_free(&tmp);
	return (buffer);
}

t_spot	ft_fdf_setup_dot(char *buffer, int x, int y)
{
	t_spot			dot;
	char			**sequence;
	char			*color;
	unsigned int	col;

	dot.x = x;
	dot.y = y;
	sequence = ft_split(buffer, ' ');
	dot.z = ft_atoi(sequence[x]);
	if (ft_strchr(sequence[x], ','))
		color = ft_strchr(sequence[x], 'x') + 1;
	col = ft_btou(color, "0123456789ABCDEF");
	dot.blue = col & 0xFF;
	dot.green = (col >> 8) & 0xFF;
	dot.red = (col >> 16) & 0xFF;
	ft_full_free((void **)sequence);
	return (dot);
}///////////

int	main(int ac, char **argv)
{
	t_vars	vars;
	t_spot	dot;
	int		fd;
	int		x;
	char	*buffer;

	fd = open(argv[ac - 1], O_RDONLY);
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
	mlx_hook(vars.win, ON_DESTROY, DestroyAll, ft_click_cross, &vars);
	mlx_loop_hook(vars.mlx, ft_frame, &vars);
	vars.rows = ft_fdf_rowcount(argv[ac - 1]);
	ft_fdf_lencheck(&vars, argv[ac - 1]);
	buffer = get_next_line(fd);
	x = 1;
	buffer = ft_fdf_buffertrim(buffer);
	dot = ft_fdf_setup_dot(buffer, x);
	(void)dot;
	while (buffer)
	{
		ft_true_free(&buffer);
		buffer = get_next_line(fd);
	}
	//ft_standard(&vars, argv[ac - 1]);
	//mlx_loop(vars.mlx);
	close(fd);
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
/*

char	*ft_fdf_buffertrim(char *buffer)
{
	char	*tmp;

	tmp = ft_strtrim(buffer, "\n");
	buffer = ft_true_free(buffer);
	buffer = ft_strtrim(tmp, " ");
	tmp = ft_true_free(tmp);
	return (buffer);
}

t_spot	*ft_fdf_init_row(char **sequence, t_spot *row)
{
	int	i;

	i = 0;
	while (sequence && sequence[i])
	{
		row[i].str = ft_strdup(sequence[i]);
		i++;
	}
	return (row);
}


t_spot	*ft_fdf_init_row(char **sequence, t_spot *row)
{
	int	i;

	i = 0;
	while (sequence && sequence[i])
	{
		row[i].str = ft_strdup(sequence[i]);
		i++;
	}
	return (row);
}


void	ft_standard(t_vars *vars, char *filename)
{
	int		fd;
	char	*buffer;
	char	**sequence;
char	*ft_fdf_buffertrim(char *buffer)
{
	char	*tmp;

	tmp = ft_strtrim(buffer, "\n");
	buffer = ft_true_free(buffer);
	buffer = ft_strtrim(tmp, " ");
	tmp = ft_true_free(tmp);
	return (buffer);
}

t_spot	*ft_fdf_init_row(char **sequence, t_spot *row)
{
	int	i;

	i = 0;
	while (sequence && sequence[i])
	{
		row[i].str = ft_strdup(sequence[i]);
		i++;
	}
	return (row);
}


t_spot	*ft_fdf_init_row(char **sequence, t_spot *row)
{
	int	i;

	i = 0;
	while (sequence && sequence[i])
	{
		row[i].str = ft_strdup(sequence[i]);
		i++;
	}
	return (row);
}


void	ft_standard(t_vars *vars, char *filename)
{
	int		fd;
	char	*buffer;
	char	**sequence;
	t_spot	*row;
	t_spot	**matrix;

	row = (t_spot *)malloc(sizeof(t_spot) * vars->len);
	matrix = (t_spot **)malloc(sizeof(row) * vars->rows);
	(void)vars;
	fd = open(filename, O_RDONLY);
	buffer = get_next_line(fd);
	while (buffer)
	{
		buffer = ft_fdf_buffertrim(buffer);
		sequence = ft_split(buffer, ' ');
		row = ft_fdf_init_row(sequence, row);
		free(sequence);
		matrix = ft_fdf_matrix(matrix, row);
		buffer = ft_true_free(buffer);
		buffer = get_next_line(fd);
	}
	close(fd);
}

int	ft_fdf_get_z(int x, char *buffer)
{
	char	**sequence;
	int		ret;

	sequence = ft_split(buffer, ' ');
	ret = ft_atoi(sequence[x]);
	free(sequence);
	sequence = NULL;
	return (ret);
}

unsigned int	ft_fdf_getcol(int x, char *buffer)
{
	char			**sequence;
	char			**section;
	unsigned int	ret;

	ret = 0x00FFFFFF;
	sequence = ft_split(buffer, ' ');
	if (ft_strchr(sequence[x], ','))
	{
		section = ft_split(sequence[x], ',');
		ret = ft_atou_base(section[1], "0123456789ABCDEF");
		free(section);
		section = NULL;
	}
	free(sequence);
	sequence = NULL;
	return (ret);
}

t_spot	ft_fdf_setup_dot(t_spot *row, t_spot dot, char *buffer)
{
	row->x = dot.x;
	row->y = dot.y;
	row->z = ft_fdf_get_z(dot.x, buffer);
	row->pixcolor = ft_fdf_getcol(dot.x, buffer);
	return (*row);
}

t_spot	**ft_fdf_matrix(t_vars *vars, int fd)
{
	t_spot	**matrix;
	t_spot	*row;
	t_spot	dot;
	char	*buffer;

	dot.x = 0;
	dot.y = 0;
	matrix = (t_spot **)malloc(sizeof(t_spot *) * vars->rows);
	while (dot.y < vars->rows)
	{
		row = (t_spot *)malloc(sizeof(t_spot) * vars->len);
		buffer = get_next_line(fd);
		buffer = ft_fdf_buffertrim(buffer);
		while (dot.x < vars->len)
		{
			row[dot.x] = ft_fdf_setup_dot(&row[dot.x], dot, buffer);
			dot.x++;
		}
		buffer = ft_true_free(buffer);
		dot.x = 0;
		dot.y++;
	}
	return (matrix);
}

	fd = open(filename, O_RDONLY);
	buffer = get_next_line(fd);
	while (buffer)
	{
		buffer = ft_fdf_buffertrim(buffer);
		sequence = ft_split(buffer, ' ');
		row = ft_fdf_init_row(sequence, row);
		free(sequence);
		matrix = ft_fdf_matrix(matrix, row);
		buffer = ft_true_free(buffer);
		buffer = get_next_line(fd);
	}
	close(fd);
}

int	ft_fdf_get_z(int x, char *buffer)
{
	char	**sequence;
	int		ret;

	sequence = ft_split(buffer, ' ');
	ret = ft_atoi(sequence[x]);
	free(sequence);
	sequence = NULL;
	return (ret);
}

unsigned int	ft_fdf_getcol(int x, char *buffer)
{
	char			**sequence;
	char			**section;
	unsigned int	ret;

	ret = 0x00FFFFFF;
	sequence = ft_split(buffer, ' ');
	if (ft_strchr(sequence[x], ','))
	{
		section = ft_split(sequence[x], ',');
		ret = ft_atou_base(section[1], "0123456789ABCDEF");
		free(section);
		section = NULL;
	}
	free(sequence);
	sequence = NULL;
	return (ret);
}

t_spot	ft_fdf_setup_dot(t_spot *row, t_spot dot, char *buffer)
{
	row->x = dot.x;
	row->y = dot.y;
	row->z = ft_fdf_get_z(dot.x, buffer);
	row->pixcolor = ft_fdf_getcol(dot.x, buffer);
	return (*row);
}

t_spot	**ft_fdf_matrix(t_vars *vars, int fd)
{
	t_spot	**matrix;
	t_spot	*row;
	t_spot	dot;
	char	*buffer;

	dot.x = 0;
	dot.y = 0;
	matrix = (t_spot **)malloc(sizeof(t_spot *) * vars->rows);
	while (dot.y < vars->rows)
	{
		row = (t_spot *)malloc(sizeof(t_spot) * vars->len);
		buffer = get_next_line(fd);
		buffer = ft_fdf_buffertrim(buffer);
		while (dot.x < vars->len)
		{
			row[dot.x] = ft_fdf_setup_dot(&row[dot.x], dot, buffer);
			dot.x++;
		}
		buffer = ft_true_free(buffer);
		dot.x = 0;
		dot.y++;
	}
	return (matrix);
}
*/
