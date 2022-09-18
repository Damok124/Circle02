/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zharzi <zharzi@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/31 13:40:17 by zharzi            #+#    #+#             */
/*   Updated: 2022/09/18 16:39:21 by zharzi           ###   ########.fr       */
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

t_spot	ft_fdf_setup_dot(char *buffer, int x, int y, t_vars *vars)
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
	else
		color = vars->hexcolor + 2;
	col = ft_btou(color, "0123456789ABCDEF");
	dot.blue = col & 0xFF;
	dot.green = (col >> 8) & 0xFF;
	dot.red = (col >> 16) & 0xFF;
	ft_full_free((void **)sequence);
	return (dot);
}

t_spot	*ft_standard(char *buffer, t_vars *vars, int y)
{
	t_spot	*row;
	int		x;

	x = 0;
	row = (t_spot *)malloc(sizeof(t_spot) * vars->len);
	while (x < vars->len)
	{
		row[x] = ft_fdf_setup_dot(buffer, x, y, vars);
		x++;
	}
	return (row);
}

t_spot	**ft_map_to_matrix(t_vars *vars, char *filename)
{
	int		fd;
	char	*buffer;
	int		y;
	t_spot	**matrix;

	matrix = (t_spot **)malloc(sizeof(t_spot *) * vars->len);
	y = 0;
	fd = open(filename, O_RDONLY);
	buffer = get_next_line(fd);
	while (buffer)
	{
		buffer = ft_fdf_buffertrim(buffer);
		matrix[y] = ft_standard(buffer, vars, y);
		y++;
		ft_true_free(&buffer);
		buffer = get_next_line(fd);
	}
	close(fd);
	return (matrix);
}

void	ft_view_dot(t_spot	dot)
{
	unsigned int	color;

	color = (dot.red << 16) + (dot.green << 8) + (dot.blue);
	ft_printf("y : %d; x : %d; z : %d\n", dot.y, dot.x, dot.z);
	ft_printf("color = %x\n", color);
}

void	ft_view_matrix(t_spot **matrix, t_vars *vars)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (y < vars->rows)
	{
		while (x < vars->len)
		{
			ft_view_dot(matrix[y][x]);
			x++;
		}
		x = 0;
		y++;
	}
}

int	main(int ac, char **argv)
{
	t_vars	vars;
	t_spot	**matrix;

	vars.mlx = mlx_init();
	if (!vars.mlx)
		return (MLX_ERROR);
	vars.win = mlx_new_window(vars.mlx, WINDOW_WIDTH, WINDOW_HEIGHT, "FDF");
	if (!vars.win)
	{
		free(vars.mlx);
		return (MLX_ERROR);
	}
	vars.hexcolor = ft_fdf_initcol();
	ft_printf("%s\n", vars.hexcolor);
	vars.color = ft_btou(vars.hexcolor + 2, "0123456789ABCDEF");
	ft_printf("%x\n", vars.color);
	vars.img = mlx_new_image(vars.mlx, WINDOW_WIDTH, WINDOW_HEIGHT);
	vars.addr = mlx_get_data_addr(vars.img, &vars.bits_per_pixel, \
		&vars.line_length, &vars.endian);
	mlx_key_hook(vars.win, ft_keypress, &vars);
	mlx_hook(vars.win, ON_DESTROY, DestroyAll, ft_click_cross, &vars);
	mlx_loop_hook(vars.mlx, ft_frame, &vars);
	vars.rows = ft_fdf_rowcount(argv[ac - 1]);
	ft_fdf_lencheck(&vars, argv[ac - 1]);
	matrix = ft_map_to_matrix(&vars, argv[ac - 1]);
	ft_view_matrix(matrix, &vars);
	ft_fdf_free_matrix(matrix, &vars);
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
