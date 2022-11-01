/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_infile_to_in.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zharzi <zharzi@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 19:50:28 by zharzi            #+#    #+#             */
/*   Updated: 2022/11/01 19:50:30 by zharzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

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
