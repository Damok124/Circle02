/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zharzi <zharzi@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 06:22:33 by zharzi            #+#    #+#             */
/*   Updated: 2022/11/01 23:31:57 by zharzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>



void	ft_cmd_not_found(char *str)
{
	write(2, "Command '", ft_strlen("Command '"));
	write(2, str, ft_strlen(str));
	write(2, "' not found.\n", ft_strlen("' not found.\n"));
}

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


char	*ft_setup_limiter(const char *src, int *cursor)
{
	size_t	i;
	size_t	size;
	char	*dst;

	i = 0;
	size = ft_strlen(src);
	dst = ft_calloc(size + 2, sizeof(char));
	while (src[i] && i < (size))
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\n';
	dst[i + 1] = '\0';
	*cursor += 1;
	return (dst);
}


void	ft_close_stdfds(void)
{
	close(STDIN);
	close(STDOUT);
	close(STDERR);
}


void	ft_print_cmderr(char **validpaths, char **argv)
{
	char	**cmd_args;
	int		i;

	i = 0;
	while (validpaths && validpaths[i])
	{
		if (validpaths[i][0] == '\0')
		{
			cmd_args = ft_split(argv[i + 2], ' ');
			ft_cmd_not_found(cmd_args[0]);
			ft_full_free((void **)cmd_args);
		}
		i++;
	}
}


char	**ft_parse_cmd(char *arg)
{
	char	**cmd;

	cmd = ft_split(arg, ' ');
	return (cmd);
}


void	ft_double_fullfree(char **strs1, char **strs2)
{
	ft_full_free((void **)strs1);
	ft_full_free((void **)strs2);
}
/*
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
*/

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


t_data	ft_init_data(int ac, char **argv, char **env)
{
	t_data	data;

	data.ac = ac;
	data.argv = argv;
	data.env = env;
	return (data);
}
/*
int	ft_here_doc(t_data *data, char *limiter)
{
	int		fd;
	int		stop;
	char	*buffer;

	stop = 0;
	buffer = NULL;
	if (data->infile && access(data->infile, F_OK) == 0)
		data->infile = ft_get_tmpname(&data->infile);
	fd = open(data->infile, O_CREAT | O_WRONLY, S_IRUSR | S_IWUSR | S_IRGRP | \
		S_IWGRP | S_IROTH);
	while (!stop)
	{
		buffer = get_next_line(STDIN);
		if (!ft_strncmp(buffer, limiter, ft_strlen(limiter)))
			stop++;
		else if (buffer)
			write(fd, buffer, ft_strlen(buffer));
		if (buffer)
			free(buffer);
	}
	buffer = get_next_line(1025);
	ft_true_free((void **)&limiter);
	return (fd);
}
*/
/*
void	ft_infile_to_stdin_b(t_data *data)
{
	int		fd;
	char	*limiter;
	char	*basename;

	basename = "tmp_pipex";
	data->infile = ft_strdup(basename);
	limiter = ft_setup_limiter(data->argv[1], &data->cursor);
	fd = ft_here_doc(data, limiter);
	close(fd);
	fd = open(data->infile, O_RDONLY);
	dup2(fd, STDIN);
	close(fd);
	data->cursor += 1;
}
*/

void	ft_infile_to_in(char **argv, char **cmd_args, char **validpaths, int i)
{
	int		fd;

	fd = -1;
	if (i == 1 && argv[1] && !access(argv[1], F_OK))
	{
		fd = open(argv[1], O_RDONLY);
		if (fd > 0)
		{
			dup2(fd, STDIN);
			close(fd);
		}
		else
		{
			ft_double_fullfree(validpaths, cmd_args);
			ft_close_stdfds();
			exit(1);
		}
	}
	else if (i == 1 && argv[1] && access(argv[1], F_OK))
	{
		ft_double_fullfree(validpaths, cmd_args);
		ft_close_stdfds();
		exit(1);
	}
}


char	*ft_get_goodpath(char **cmd, char **fullpaths)
{
	int		i;
	char	*clone;

	i = 0;
	clone = NULL;
	if (cmd && !access(cmd[0], F_OK | X_OK))
		clone = ft_strdup(cmd[0]);
	else
	{
		while (fullpaths && fullpaths[i] && access(fullpaths[i], F_OK | X_OK))
			i++;
		if (fullpaths && fullpaths[i])
			clone = ft_strdup(fullpaths[i]);
		else
			clone = ft_strdup("");
	}
	return (clone);
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


int	ft_test_files(char **argv, int ac)
{
	if (ft_such_file(argv[1]))
		ft_infile_permission(argv[1]);
	if (!ft_outfile_permission(argv[ac - 1]))
		return (0);
	return (1);
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
char	*ft_get_validpath_b(t_data *data)
{
	int	i;

	i = 0;
	if (!access(data->cmd[0], F_OK | X_OK))
		return (data->cmd[0]);
	while (data->fullpaths && data->fullpaths[i] && access(data->fullpaths[i], \
		F_OK | X_OK))
		i++;
	if (data->fullpaths && data->fullpaths[i])
		return (data->fullpaths[i]);
	else
		ft_cmd_not_found(data->cmd[0]);
	return (NULL);
}
*/

int	ft_check_tmpname(char *tmpname)
{
	if (tmpname && access(tmpname, F_OK) == -1)
		return (1);
	return (0);
}

char	*ft_get_tmpname(char **basename)
{
	char	*tmpname;
	char	*nb;
	int		test;
	int		max;
	int		i;

	i = 1;
	test = 0;
	max = INT_MAX;
	tmpname = NULL;
	while (!test && i < max)
	{
		nb = ft_itoa(-i);
		tmpname = ft_strjoin(*basename, nb);
		test = ft_check_tmpname(tmpname);
		if (!test)
			ft_true_free((void **)&tmpname);
		ft_true_free((void **)&nb);
		i++;
	}
	ft_true_free((void **)basename);
	return (tmpname);
}


char	**ft_get_paths(char **env)
{
	int		i;
	int		len;
	char	**tmp;
	char	**paths;

	i = 0;
	while (env && env[i] && ft_strncmp(env[i], "PATH=", 5))
		i++;
	tmp = ft_split(env[i] + 5, ':');
	len = ft_count_strs(env[i], ':');
	paths = (char **)malloc(sizeof(char *) * (len + 1));
	paths[len] = NULL;
	i = 0;
	while (tmp[i])
	{
		paths[i] = ft_strjoin(tmp[i], "/");
		i++;
	}
	ft_full_free((void **)tmp);
	tmp = NULL;
	return (paths);
}

/*
void	ft_get_next_cmd_b(t_data *data)
{
	data->cmd = ft_parse_cmd(data->argv[data->cursor]);
	if (*data->cmd)
	{
		data->paths = ft_get_paths(data->env);
		data->fullpaths = ft_get_fullpaths(data->paths, data->cmd[0]);
		data->validpath = ft_get_validpath_b(data);
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


void	ft_clean_connect(int std, int toconnect, int toclose)
{
	dup2(toconnect, std);
	close(toconnect);
	close(toclose);
}



void	ft_pipex(t_data *data, char **validpaths)
{
	int			pfds[2];
	char		**cmd_args;
	static int	i;

	i++;
	cmd_args = ft_split(data->argv[i + 1], ' ');
	pipe(pfds);
	if (validpaths[i - 1] && validpaths[i - 1][0] != '\0' && !fork())
	{
		ft_clean_connect(STDOUT, pfds[WRITE_END], pfds[READ_END]);
		ft_infile_to_in(data->argv, cmd_args, validpaths, i);
		execve(validpaths[i - 1], cmd_args, data->env);
	}
	else
	{
		ft_clean_connect(STDIN, pfds[READ_END], pfds[WRITE_END]);
		ft_full_free((void **)cmd_args);
		if ((i + 1) < (data->ac - 3))
			ft_pipex(data, validpaths);
		else
		{
			cmd_args = ft_split(data->argv[i + 2], ' ');
			ft_outfile_to_out(validpaths, i, cmd_args, data);
		}
	}
}
/*
int	main_bonus(t_data *data)
{
	char	**paths;
	char	**validpaths;

	paths = ft_get_paths(data->env);
	validpaths = ft_get_validpaths(data->ac, data->argv, paths);
	ft_full_free((void **)paths);
	//if (ft_test_files(data->argv, data->ac))
	//	ft_pipex(&data, validpaths);
	//ft_print_cmderr(validpaths, data->argv);
	//waitpid(-1, NULL, 0);
	//ft_full_free((void **)validpaths);
	ft_close_stdfds();
	exit(1);
}
*/
int	main(int ac, char **argv, char **env)
{
	t_data	data;
	char	**paths;
	char	**validpaths;

	data = ft_init_data(ac, argv, env);
	if (ac >= 5 && ft_strncmp(argv[1], "here_doc", 9))
	{
		paths = ft_get_paths(env);
		validpaths = ft_get_validpaths(ac, argv, paths);
		ft_full_free((void **)paths);
		if (ft_test_files(argv, ac))
			ft_pipex(&data, validpaths);
		ft_print_cmderr(validpaths, argv);
		waitpid(-1, NULL, 0);
		ft_full_free((void **)validpaths);
	}
	//else if (ac >= 6 && !ft_strncmp(argv[1], "here_doc", 9))
	//	main_bonus(&data);
	else
		write(2, "ERROR : wrong number of arguments.\n", 35);
	ft_close_stdfds();
	return (0);
}
