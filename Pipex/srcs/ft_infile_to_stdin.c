/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_infile_to_stdin.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zharzi <zharzi@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/01 00:26:57 by zharzi            #+#    #+#             */
/*   Updated: 2022/10/28 12:36:12 by zharzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
/*
void	ft_infile_to_stdin(t_data *data)
{
	int		fd;

	if (!access(data->argv[0], F_OK) && access(data->argv[0], R_OK))
	{
		ft_err_msg(data->argv[0], ": Permission denied\n");
		//test = 0;
	}
	else if (!data->infile && access(data->argv[0], F_OK))
	{
		ft_err_msg(data->argv[0], ": No such file or directory\n");
		//test = 1;
	}
	else if (data->infile && !access(data->infile, F_OK))
	{
		fd = open(data->infile, O_RDONLY);
		if (fd > 0)
		{
			dup2(fd, STDIN);
			close(fd);
		}
	}
	else
		data->infile = NULL;
	if (!access(data->outfile, F_OK) && access(data->outfile, W_OK))
	{
		ft_err_msg(data->outfile, ": Permission denied\n");
		//test = 0;
	}
	data->cursor += 1;
}
*/
