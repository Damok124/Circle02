/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_outfile_to_out.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zharzi <zharzi@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 20:07:32 by zharzi            #+#    #+#             */
/*   Updated: 2022/11/01 20:07:34 by zharzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_outfile_to_out(char **paths, int i, char **cmd_a, t_data *data)
{
	int		fdof;
	char	*outfile;

	outfile = data->argv[data->ac - 1];
	fdof = open(outfile, O_WRONLY | O_TRUNC | O_CREAT, \
		S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH);
	if (fdof > 0)
	{
		dup2(fdof, 1);
		close(fdof);
		if (!fork())
		{
			if (paths[i] && paths[i][0] != '\0')
				execve(paths[i], cmd_a, data->env);
			else
			{
				ft_double_fullfree(paths, cmd_a);
				ft_close_stdfds();
				exit(1);
			}
		}
	}
	else
		perror(outfile);
	ft_full_free((void **)cmd_a);
}
