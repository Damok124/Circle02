/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zharzi <zharzi@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 06:22:33 by zharzi            #+#    #+#             */
/*   Updated: 2022/10/20 01:53:23 by zharzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_err_msg(char *filename, char *str)
{
	write(2, "bash: ", ft_strlen("bash: "));
	write(2, filename, ft_strlen(filename));
	write(2, str, ft_strlen(str));
}

void	ft_print_error_msg(t_data *data)
{
	if (!access(data->outfile, F_OK) && access(data->outfile, W_OK))
		ft_err_msg(data->argv[data->ac - 1], ": Permission denied\n");
	if (!data->infile && access(data->argv[0], F_OK))
		ft_err_msg(data->argv[0], ": No such file or directory\n");
	if (!data->infile && !access(data->argv[0], F_OK))
		ft_err_msg(data->argv[0], ": Permission denied\n");
}

void	ft_init_data(t_data *data, int ac, char **argv, char **env)
{
	data->ac = ac - 1;
	data->infile = argv[1];
	data->outfile = argv[ac - 1];
	data->argv = argv + 1;
	data->env = env;
}

void	ft_pipex(t_data *data)
{
	int	pfds[2];

	ft_get_next_cmd(data);
	pipe(pfds);
	if (data->validpath && !fork())
	{
		ft_clean_connect(STDOUT, pfds[WRITE_END], pfds[READ_END]);
		if (data->infile || data->cursor != 2)
			execve(data->validpath, data->cmd, data->env);
	}
	else
	{
		ft_clean_connect(STDIN, pfds[READ_END], pfds[WRITE_END]);
		if (ft_strncmp(data->infile, "/dev/urandom", 12))
			waitpid(-1, NULL, 0);
		ft_free_data(data);
		if (data->cursor < data->ac - 2)
			ft_pipex(data);
		else
			ft_outfile_to_stdout(data);
		close(pfds[READ_END]);
	}
}

int	main(int ac, char **argv, char **env)
{
	t_data	data;

	if (ac == 5)
	{
		data.cursor = 0;
		ft_init_data(&data, ac, argv, env);
		ft_infile_to_stdin(&data);
		ft_print_error_msg(&data);
		ft_pipex(&data);
		ft_free_data(&data);
		close(STDIN);
		close(STDOUT);
		close(STDERR);
	}
	else
		perror("ERROR : wrong number of arguments.\n");
	return (0);
}
