/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_outfile_to_stdout_bonus.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zharzi <zharzi@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/02 00:59:35 by zharzi            #+#    #+#             */
/*   Updated: 2022/10/16 18:15:31 by zharzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	ft_outfile_to_stdout_b(t_data *data)
{
	int	fdof;

	ft_get_next_cmd(data);
	fdof = open(data->outfile, O_RDWR | O_APPEND | O_CREAT, S_IRUSR | \
		S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH);
	dup2(fdof, 1);
	if (!fork())
		execve(data->validpath, data->cmd, data->env);
	else
		waitpid(0, NULL, 0);
}
