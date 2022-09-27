/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zharzi <zharzi@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 06:22:33 by zharzi            #+#    #+#             */
/*   Updated: 2022/09/27 23:51:10 by zharzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*ft_get_paths(char **env)
{
	int	i;

	i = 0;
	while (env && env[i] && ft_strncmp(env[i], "PATH=", 5))
		i++;
	return (env[i] + 5);
}

int	main(int ac, char *argv[], char **env)
{
	int		test;
	char	*str;
	char	**paths;

	if (ac == 5)
	{
		test = access("/usr/bin/ls", F_OK);
		str = ft_get_paths(env);
		paths = ft_split(str, ':');
	}
	execve(path, argv, env)
	(void)argv;
	return (0);
}

/*
	open,//
	close,//
	write,//
	malloc,//
	free,//
		perror,
		strerror,
	access,
	dup2,
	execve,
	exit,
	fork,
	pipe,
		unlink,
	waitpid

strjoin les paths avec les cmd
execve
*/
