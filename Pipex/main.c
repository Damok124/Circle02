/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zharzi <zharzi@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 06:22:33 by zharzi            #+#    #+#             */
/*   Updated: 2022/10/01 02:07:59 by zharzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_test(t_data *data)
{
	int	pfds[2];

	(void)data;
	pipe(pfds);
	if (!fork())
	{
		dup2(pfds[1], STDOUT);
		close(pfds[0]);
	}
	else
	{
		dup2(pfds[0], STDIN);
		close(pfds[1]);
	}
	ft_printf("%d %d", pfds[0], pfds[1]);
}

void	ft_pipex(t_data *data)
{
	ft_infile_to_stdin(data);
	//while (data->cursor < data->ac - 1)
	//{
	//	if (data->cursor != 1)
	//	{
	//	}
		data->cmd = ft_parse_cmd(data->argv[data->cursor]);
		data->paths = ft_get_paths(data->env);
		data->fullpaths = ft_get_fullpaths(data->paths, data->cmd[0]);
		data->validpath = ft_get_validpath(data);
		//creation du pipe de sorte que fd1 devienne fdin du fichier
		//ft_exec_cmd(data->validpath, data->cmd, data->env);
		ft_test(data);
		ft_free_data(data);
		data->cursor += 1;
	//}
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
		ft_pipex(&data);

		//close(STDIN);
		//close(STDOUT);
		//close(STDERR);
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
