/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_outfile_to_stdout.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zharzi <zharzi@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/02 00:59:35 by zharzi            #+#    #+#             */
/*   Updated: 2022/10/02 01:06:30 by zharzi           ###   ########.fr       */
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
	if (!fork())
		execve(data->validpath, data->cmd, data->env);
	else
		waitpid(0, NULL, 0);
}
