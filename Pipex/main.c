/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zharzi <zharzi@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 06:22:33 by zharzi            #+#    #+#             */
/*   Updated: 2022/10/02 02:24:15 by zharzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_pipex(t_data *data)
{
	int	pfds[2];

	ft_get_next_cmd(data);
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
		if (data->cursor < data->ac - 2)
			ft_pipex(data);
		else
			ft_outfile_to_stdout(data);
	}
	close(pfds[0]);
	close(pfds[1]);
}

int	main(int ac, char **argv, char **env)
{
	t_data	data;

	if (ac > 4 )
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
