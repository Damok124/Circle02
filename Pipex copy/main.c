/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zharzi <zharzi@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 06:22:33 by zharzi            #+#    #+#             */
/*   Updated: 2022/10/26 20:32:03 by zharzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_pipex(t_data *data)
{
	int	pfds[2];

	ft_get_next_cmd(data);
	pipe(pfds);
	if (data->validpath && !fork())
	{
		ft_printf("cmd=%s vpath=%s\n", *data->cmd, data->validpath);
		ft_clean_connect(STDOUT, pfds[WRITE_END], pfds[READ_END]);
		if (data->infile || data->cursor != 2)
			execve(data->validpath, data->cmd, data->env);
	}
	else
	{
		ft_clean_connect(STDIN, pfds[READ_END], pfds[WRITE_END]);
		ft_free_data(data);
		if (data->cursor < data->ac - 2)
			ft_pipex(data);
		else
			ft_outfile_to_stdout(data);
		close(pfds[READ_END]);
	}
}

//fd ouvert restant//revoir condition if avant fork pipex, tenter null vpath

int	main(int ac, char **argv, char **env)
{
	t_data	data;

	if (ac >= 5)
	{
		ft_init_data(&data, ac, argv, env);
		ft_infile_to_stdin(&data);
		ft_pipex(&data);
		ft_free_data(&data);
		waitpid(-1, NULL, 0);
	}
	else
		write(2, "ERROR : wrong number of arguments.\n", 35);
	close(STDIN);
	close(STDOUT);
	close(STDERR);
	return (0);
}
