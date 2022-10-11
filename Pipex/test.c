/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zharzi <zharzi@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/30 18:26:47 by zharzi            #+#    #+#             */
/*   Updated: 2022/10/11 18:46:55 by zharzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(void)
{
	char *str = "Bonjour";

	ft_printf("%s-%p\n", str, str);
	return (0);
}

/*
int	main(int ac, char **argv, char **env)
{
	int		fd;
	char	*buffer;
	int		stop;
	char	*limiter;

	stop = 0;
	limiter = ft_setup_limiter(argv[2]);
	fd = open("/tmp", __O_TMPFILE | O_RDWR, S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH);
	ft_printf("%d\n", fd);
	while (!stop)
	{
		buffer = get_next_line(STDIN);
		if (!ft_strncmp(buffer, limiter, ft_strlen(limiter)))
			stop++;
		else if (buffer)
		{
			//ft_printf("%d, %s, %d\n", fd, buffer, ft_strlen(buffer));
			write(fd, buffer, (int)ft_strlen(buffer));
		}
		if (buffer)
			free(buffer);
	}
	close(fd);
	ft_printf("%s\n", get_next_line(4));
	buffer = get_next_line(1025);
	free(limiter);
	(void)ac;
	(void)argv;
	(void)env;
	close(fd);
	//unlink("./file9");
	return (0);
}

int	main(int ac, char **argv, char **env)
{
	int		fd;
	int		len;
	char	*buffer;
	int		stop;
	char	*speargv;

	(void)ac;
	stop = 0;
	len = ft_strlen(argv[2]) + 1;
	speargv = ft_calloc(sizeof(char) * (len + 1), 1);
	ft_strlcpy(speargv, argv[2], len + 1);
	speargv[len - 1] = '\n';
	(void)env;
	fd = open("/tmp", __O_TMPFILE | O_WRONLY, S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH);
	while (!stop)
	{
		buffer = get_next_line(0);
		if (!ft_strncmp(buffer, speargv, len))
			stop++;//return
		else if (buffer)
			write(fd, buffer, ft_strlen(buffer));
		free(buffer);
	}
	free(speargv);
	close(fd);
	return (0);
}
*/
