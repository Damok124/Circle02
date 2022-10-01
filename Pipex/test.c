/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zharzi <zharzi@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/30 18:26:47 by zharzi            #+#    #+#             */
/*   Updated: 2022/10/02 00:33:46 by zharzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_pipex(t_data *data)
{
	int	pfds[2];
	int	fdof;

	data->cmd = ft_parse_cmd(data->argv[data->cursor]);
	data->paths = ft_get_paths(data->env);
	data->fullpaths = ft_get_fullpaths(data->paths, data->cmd[0]);
	data->validpath = ft_get_validpath(data);
	data->cursor += 1;
	pipe(pfds);
	if (!fork())
	{
		dup2(pfds[WRITE_END], STDOUT);
		close(pfds[READ_END]);
		execve(data->validpath, data->cmd, data->env);
	}
	else
	{
		dup2(pfds[READ_END], STDIN);
		close(pfds[WRITE_END]);
		waitpid(0, NULL, 0);
		ft_free_data(data);
		data->cmd = ft_parse_cmd(data->argv[data->cursor]);
		data->paths = ft_get_paths(data->env);
		data->fullpaths = ft_get_fullpaths(data->paths, data->cmd[0]);
		data->validpath = ft_get_validpath(data);
		fdof = open(data->outfile, O_RDWR | O_TRUNC | O_CREAT, S_IRUSR | \
			S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH);
		dup2(fdof, 1);
		if (!fork())
			execve(data->validpath, data->cmd, data->env);
		else
			waitpid(0, NULL, 0);
		close(pfds[0]);
		close(pfds[1]);
	}
}

int	main(int ac, char **argv, char **env)
{
	t_data	data;

	if (ac == 5)
	{
		data.ac = ac - 1;
		data.cursor = 0;
		data.infile = argv[1];
		data.outfile = argv[ac - 1];
		data.argv = argv + 1;
		data.env = env;
		ft_infile_to_stdin(&data);
		ft_pipex(&data);

		ft_free_data(&data);
		close(STDIN);
		close(STDOUT);
		close(STDERR);
	}
	return (EXIT_SUCCESS);
}

/*
	open,//
	close,//
	write,//
	malloc,//
	free,//
		perror,
		strerror,
	access,
	dup2,
	execve,
	exit,
	fork,
	pipe,
		unlink,
	waitpid

strjoin les paths avec les cmd
execve
*/
