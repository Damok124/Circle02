/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zharzi <zharzi@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 06:22:33 by zharzi            #+#    #+#             */
/*   Updated: 2022/11/03 23:30:31 by zharzi           ###   ########.fr       */
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



void	ft_close_stdfds(void)
{
	close(STDIN);
	close(STDOUT);
	close(STDERR);
}


void	ft_print_cmderr(char **validpaths, char **argv)////////////////////////////
{
	char	**cmd_args;
	int		i;

	i = 0;
	if (!ft_strncmp(argv[1], "here_doc", 9))
		argv = argv + 1;
	while (validpaths && validpaths[i])
	{
		printf("%s\n", validpaths[i]);
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



void	ft_clean_exit(char **validpaths, char **cmd_args)
{
	ft_double_fullfree(validpaths, cmd_args);
	ft_close_stdfds();
	exit(1);
}

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
				ft_clean_exit(paths, cmd_a);
		}
	}
	else
		perror(outfile);
	ft_full_free((void **)cmd_a);
}

void	ft_append_to_outfile(char **paths, int i, char **cmd_a, t_data *data)
{
	int		fdof;
	char	*outfile;

	outfile = data->argv[data->ac - 1];
	fdof = open(outfile, O_RDWR | O_APPEND | O_CREAT, S_IRUSR | \
		S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH);
	if (fdof > 0)
	{
		dup2(fdof, 1);
		close(fdof);
		if (!fork())
		{
			if (paths[i] && paths[i][0] != '\0')
				execve(paths[i], cmd_a, data->env);
			else
				ft_clean_exit(paths, cmd_a);
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
			ft_clean_exit(validpaths, cmd_args);
	}
	else if (i == 1 && argv[1] && access(argv[1], F_OK))
		ft_clean_exit(validpaths, cmd_args);
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
	if (ac >= 5 && ft_strncmp(argv[1], "here_doc", 9))
	{
		if (ft_such_file(argv[1]))
			ft_infile_permission(argv[1]);
	}
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

void	ft_clean_connect(int std, int toconnect, int toclose)
{
	dup2(toconnect, std);
	close(toconnect);
	close(toclose);
}

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

int	ft_heredoc_to_file(char **infile, char *limiter)
{
	int		fd;
	int		stop;
	char	*buffer;

	stop = 0;
	buffer = NULL;
	if (*infile && access(*infile, F_OK) == 0)
		*infile = ft_get_tmpname(infile);
	fd = open(*infile, O_CREAT | O_WRONLY, S_IRUSR | S_IWUSR | S_IRGRP | \
		S_IWGRP | S_IROTH);
	while (!stop)
	{
		buffer = get_next_line(STDIN);
		if (!ft_strncmp(buffer, limiter, ft_strlen(limiter)))
			stop++;
		else if (buffer)
			write(fd, buffer, ft_strlen(buffer));
		if (buffer)
			ft_true_free((void **)&buffer);
	}
	buffer = get_next_line(1024 + (STDIN + 1));
	ft_true_free((void **)&limiter);
	return (fd);
}

char	*ft_setup_limiter(const char *src)
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
	return (dst);
}

char	*ft_heredoc_to_in(char **argv, char **cmd_args, char **validpaths, int i)
{
	int		fd;
	char	*limiter;
	char	*infile;

	if (i == 1)
	{
		infile = ft_strdup("tmp_pipex");
		limiter = ft_setup_limiter(argv[2]);
		fd = ft_heredoc_to_file(&infile, limiter);
		if (fd > 0)
		{
			close(fd);
			fd = open(infile, O_RDONLY);
			if (fd < 0)
				ft_clean_exit(validpaths, cmd_args);
			dup2(fd, STDIN);
			close(fd);
			return (infile);
		}
		else
			ft_clean_exit(validpaths, cmd_args);
	}
	return (NULL);
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

void	ft_parent_hdoc(t_data *data, char **cmd_args, char **validpaths, int i)
{
	cmd_args = ft_split(data->argv[i + 3], ' ');
	ft_append_to_outfile(validpaths, i, cmd_args, data);
}

void	ft_unlink(char *filename)
{
	if (filename)
		unlink(filename);
}

char	*ft_pipex_heredoc(t_data *data, char **validpaths, char *infile)
{
	int			pfds[2];
	char		**cmd_args;
	static int	i;

	i++;
	cmd_args = ft_split(data->argv[i + 2], ' ');
	pipe(pfds);
	if (validpaths[i - 1] && validpaths[i - 1][0] != '\0' && !fork())
	{
		ft_clean_connect(STDOUT, pfds[WRITE_END], pfds[READ_END]);
		if (!infile)
			infile = ft_heredoc_to_in(data->argv, cmd_args, validpaths, i);
		ft_unlink(infile);
		execve(validpaths[i - 1], cmd_args, data->env);
	}
	else
	{
		ft_clean_connect(STDIN, pfds[READ_END], pfds[WRITE_END]);
		ft_full_free((void **)cmd_args);
		if ((i + 1) < (data->ac - 4))
			ft_pipex_heredoc(data, validpaths, infile);
		else
			ft_parent_hdoc(data, cmd_args, validpaths, i);
	}
	return (infile);
}

int	main_bonus(t_data *data)// regler la gestion cpu lorsque le pipe est broken
//ET AUSSI les fichiers tmp créés mais pas détruit
{
	char	**paths;
	char	**validpaths;
	char	*infile;

	infile = NULL;
	paths = ft_get_paths(data->env);
	validpaths = ft_get_validpaths(data->ac - 1, data->argv + 1, paths);
	ft_full_free((void **)paths);
	if (ft_test_files(data->argv, data->ac))
		infile = ft_pipex_heredoc(data, validpaths, infile);
	ft_print_cmderr(validpaths, data->argv);
	waitpid(-1, NULL, 0);
	ft_full_free((void **)validpaths);
	ft_close_stdfds();
	exit(1);
}

int	main(int ac, char **argv, char **env)
{
	t_data	data;
	char	**paths;
	char	**validpaths;

	data = ft_init_data(ac, argv, env);
	if (ac >= 6 && !ft_strncmp(argv[1], "here_doc", 9))
		main_bonus(&data);
	else if (ac >= 5 && ft_strncmp(argv[1], "here_doc", 9))
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
	else
		write(2, "ERROR : wrong number of arguments.\n", 35);
	ft_close_stdfds();
	return (0);
}
