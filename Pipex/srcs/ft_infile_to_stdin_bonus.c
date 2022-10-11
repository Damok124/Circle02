/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_infile_to_stdin_bonus.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zharzi <zharzi@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/01 00:26:57 by zharzi            #+#    #+#             */
/*   Updated: 2022/10/11 19:00:14 by zharzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int	ft_here_doc(char **infile)
{
	int		fd;
	int		stop;
	char	*buffer;
	char	*limiter;

	stop = 0;
	limiter = ft_setup_limiter(*infile);
	*infile = ft_available_filename("tmp_pipex-XXXXXXXX");
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
			free(buffer);
	}
	buffer = get_next_line(1025);
	ft_true_free((void **)&limiter);
	return (fd);
}

void	ft_infile_to_stdin_b(t_data *data)
{
	int		fd;

	fd = ft_here_doc(&data->infile);
	dup2(fd, STDIN);
	close(fd);
	ft_printf("test");
	data->cursor += 1;
}
