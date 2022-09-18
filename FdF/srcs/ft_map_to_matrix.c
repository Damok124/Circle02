/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_to_matrix.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zharzi <zharzi@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 21:52:53 by zharzi            #+#    #+#             */
/*   Updated: 2022/09/18 18:47:31 by zharzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

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
		matrix[y] = ft_fdf_init_rows(buffer, vars, y);
		y++;
		ft_true_free(&buffer);
		buffer = get_next_line(fd);
	}
	close(fd);
	return (matrix);
}
