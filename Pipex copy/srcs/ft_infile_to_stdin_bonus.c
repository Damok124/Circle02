/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_infile_to_stdin_bonus.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zharzi <zharzi@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/01 00:26:57 by zharzi            #+#    #+#             */
/*   Updated: 2022/10/20 23:55:42 by zharzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

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
