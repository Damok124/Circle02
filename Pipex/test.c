/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zharzi <zharzi@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/30 18:26:47 by zharzi            #+#    #+#             */
/*   Updated: 2022/10/01 00:08:11 by zharzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_infile_to_in(t_data *data)
{
	int		fd;

	fd = open(data->infile, O_RDONLY);
	dup2(fd, STDIN);
	close(fd);
	data->cursor += 1;
}

void	ft_pipex(t_data *data)
{
	ft_infile_to_in(data);
	//while (data->cursor < data->ac - 1)
	//{
	//	if (data->cursor != 1)
	//	{
	//	}
		data->cmd = ft_parse_cmd(data->argv[1]);
		data->fullpaths = ft_get_fullpaths(data->paths, data->cmd[0]);
		data->validpath = ft_get_validpath(data);
		ft_exec_cmd(data->validpath, data->cmd, data->env);
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
		data.paths = ft_get_paths(env);
		ft_pipex(&data);
		ft_full_free((void **)data.cmd);
		ft_full_free((void **)data.paths);
		ft_full_free((void **)data.fullpaths);
		close(STDIN);
		close(STDOUT);
		close(STDERR);
	}
	(void)data;
	return (EXIT_SUCCESS);
}
