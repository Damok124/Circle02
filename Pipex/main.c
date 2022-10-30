/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zharzi <zharzi@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 06:22:33 by zharzi            #+#    #+#             */
/*   Updated: 2022/10/31 00:30:11 by zharzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	ft_such_file(char *filename)
{
	char	*msg;

	if (access(filename, F_OK))
	{
		msg = ft_strjoin("pipex: ", filename);
		perror(msg);
		ft_true_free((void **)&msg);
		return (0);
	}
	return (1);
}

int	ft_infile_permission(char *filename)
{
	char	*msg;

	if (!access(filename, F_OK) && access(filename, R_OK))
	{
		msg = ft_strjoin("pipex: ", filename);
		perror(msg);
		ft_true_free((void **)&msg);
		return (0);
	}
	return (1);
}

int	ft_outfile_permission(char *filename)
{
	char	*msg;

	if (!access(filename, F_OK) && access(filename, W_OK))
	{
		msg = ft_strjoin("pipex: ", filename);
		perror(msg);
		ft_true_free((void **)&msg);
		return (0);
	}
	return (1);
}

char	*ft_get_goodpath(char **cmd, char **fullpaths)
{
	int		i;
	char	*clone;

	i = 0;
	clone = NULL;
	if (cmd && !access(cmd[0], F_OK | X_OK))
		return (cmd[0]);
	while (fullpaths && fullpaths[i] && access(fullpaths[i], F_OK | X_OK))
		i++;
	if (fullpaths && fullpaths[i])
	{
		clone = ft_strdup(fullpaths[i]);
		return (clone);
	}
	return (NULL);
}

char	**ft_get_fullpaths(char **paths, char *cmd)
{
	char	**fullpaths;
	int		i;

	i = 0;
	while (*paths && paths[i])
		i++;
	fullpaths = (char **)malloc(sizeof(char *) * (i + 1));
	if (!fullpaths)
		return (0);
	fullpaths[i] = NULL;
	while (--i >= 0)
		fullpaths[i] = ft_strjoin(paths[i], cmd);
	return (fullpaths);
}

char	**ft_get_validpaths(int ac, char **argv, char **paths)
{
	int		i;
	char	**cmd;
	char	**fullpaths;
	char	**validpaths;

	i = 0;
	validpaths = (char **)malloc(sizeof(char *) * ac - 2);
	if (!validpaths)
		return (NULL);
	validpaths[ac - 3] = NULL;
	while (i < ac - 3)
	{
		cmd = ft_parse_cmd(argv[i + 2]);
		fullpaths = ft_get_fullpaths(paths, cmd[0]);
		validpaths[i] = ft_get_goodpath(cmd, fullpaths);
		ft_full_free((void **)cmd);
		ft_full_free((void **)fullpaths);
		i++;
	}
	return (validpaths);
}

/*
void	ft_get_next_cmd(t_data *data)
{
	data->cmd = ft_parse_cmd(data->argv[data->cursor]);
	if (*data->cmd)
	{
		data->paths = ft_get_paths(data->env);
		data->fullpaths = ft_get_fullpaths(data->paths, data->cmd[0]);
		data->validpath = ft_get_validpath(data);
	}
	else
	{
		ft_cmd_not_found("");
		data->paths = ft_get_paths(data->env);
		data->fullpaths = ft_get_fullpaths(data->paths, data->cmd[0]);
		data->validpath = NULL;
	}
	data->cursor += 1;
}
*/

void	ft_outfile_to_out(char *path, char **cmd, char **env, char *outfile)
{
	int	fdof;

	fdof = open(outfile, O_RDWR | O_TRUNC | O_CREAT, S_IRUSR | \
		S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH);
	if (fdof > 0)
	{
		dup2(fdof, 1);
		if (path && !fork())
			execve(path, cmd, env);
	}
	else
		perror(outfile);
	ft_full_free((void **)cmd);
}

void	ft_pipex(int ac, char **argv, char **env, char **validpaths)
{
	int			pfds[2];
	char		**cmd_args;
	static int	i;

	i++;
	cmd_args = ft_split(argv[i + 1], ' ');
	pipe(pfds);
	if (validpaths[i - 1] && !fork())
	{
		ft_clean_connect(STDOUT, pfds[WRITE_END], pfds[READ_END]);
		execve(validpaths[i - 1], cmd_args, env);
	}
	else
	{
		ft_clean_connect(STDIN, pfds[READ_END], pfds[WRITE_END]);
		ft_full_free((void **)cmd_args);
		if (i < ac - 3)
			ft_pipex(ac, argv, env, validpaths);
		else
		{
			cmd_args = ft_split(argv[i + 2], ' ');
			ft_outfile_to_out(validpaths[i - 1], cmd_args, env, argv[ac - 1]);
		}
		close(pfds[READ_END]);
	}
	(void)ac;
}

int	ft_test_files(char **argv, int ac)
{
	if (ft_such_file(argv[1]))
		ft_infile_permission(argv[1]);
	if (!ft_outfile_permission(argv[ac - 1]))
		return (0);
	return (1);
}

void	ft_infile_to_in(char **argv)
{
	int		fd;

	fd = -1;
	if (argv[1] && !access(argv[1], F_OK))
	{
		fd = open(argv[1], O_RDONLY);
		if (fd > 0)
		{
			dup2(fd, STDIN);
			close(fd);
		}
	}
}

int	main(int ac, char **argv, char **env)
{
	char	**paths;
	char	**validpaths;

	if (ac >= 5 && env)
	{
		paths = ft_get_paths(env);
		validpaths = ft_get_validpaths(ac, argv, paths);
		if (ft_test_files(argv, ac))
		{
			ft_infile_to_in(argv);
			ft_pipex(ac, argv, env, validpaths);
		}
		waitpid(-1, NULL, 0);
		ft_full_free((void **)paths);
		ft_full_free_nb((void **)validpaths, ac - 3);
	}
	else
		write(2, "ERROR : wrong number of arguments.\n", 35);
	return (0);
}

/*
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
*/
//	.tests bash
//
//	.simple
//	.infile
//	.si  in, cmdok, cmdok,  out > out parfait
//	.si !in, cmdok, cmdok, !out > print "no such file..", out parfait outok
//	.si Xin, cmdok, cmdok, !out > print "no such file..", out parfait outok
//	.outfile
//	.si  in, cmdok, cmdok, !out > out parfait
//	.si  in, cmdok, cmdok, Xout > out inchangé
//	.cmd
//	.si  in, cmdKO, cmdok,  out > print "command not found..", out parfait
//	.si  in, cmdok, cmdKO,  out > print "command not found..", out vide
//
//	.double
//	.files
//	.si Xin, cmdok, cmdok, Xout > print "out perm deny", print "in perm deny"
//	.si !in, cmdok, cmdok, Xout > print "no such file", print "out perm deny"
//	.cmd
//	.si  in, cmdKO, cmdKO, !out > print "cmd not found", print "cmd not found"
//	.
//	.complexes
//	.si !in, cmdKO, cmdok,  out > print "No such file..", out ok
//	.si !in, cmdKO, cmdok, !out > print "No such file..", out ok
//	.si !in, cmdKO, cmdok, Xout > print "No such file..", "Perm deny"
//	.si !in, cmdKO, cmdKO, !out > print "No such file..", "cmd2 notf", out vide
//	.si !in, cmdKO, cmdKO, Xout > print "No such file..", "Perm deny"
//	.si !in, cmdok, cmdKO, Xout > print "No such file..", "Perm deny"
//	.
//	.si Xin, cmdKO, cmdok,  out > print "Perm deny", out ok
//	.si Xin, cmdKO, cmdok, !out > print "Perm deny", out ok
//	.si Xin, cmdKO, cmdok, Xout > print "in perm deny", print "out perm deny"
//	.si Xin, cmdKO, cmdKO, !out > print "Perm deny" print "cmd not found" CREout
//	.si Xin, cmdKO, cmdKO, Xout > print "in perm deny", print "out perm deny"
//	.si Xin, cmdok, cmdKO, Xout > print "out perm deny", print "in perm deny"
//	.
