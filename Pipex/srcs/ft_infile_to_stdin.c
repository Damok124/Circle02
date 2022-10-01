/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_infile_to_stdin.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zharzi <zharzi@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/01 00:26:57 by zharzi            #+#    #+#             */
/*   Updated: 2022/10/01 00:31:44 by zharzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_infile_to_stdin(t_data *data)
{
	int		fd;

	fd = open(data->infile, O_RDONLY);
	dup2(fd, STDIN);
	close(fd);
	data->cursor += 1;
}
