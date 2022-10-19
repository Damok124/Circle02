/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_outfile_to_stdout.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zharzi <zharzi@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/02 00:59:35 by zharzi            #+#    #+#             */
/*   Updated: 2022/10/20 01:47:50 by zharzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_outfile_to_stdout(t_data *data)
{
	int	fdof;

	ft_get_next_cmd(data);
	fdof = open(data->outfile, O_RDWR | O_TRUNC | O_CREAT, S_IRUSR | \
		S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH);
	dup2(fdof, 1);
	if (data->validpath && !fork())
		execve(data->validpath, data->cmd, data->env);
	else if (ft_strncmp(data->infile, "/dev/urandom", 12))
		waitpid(0, NULL, 0);
}
