/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_paths.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zharzi <zharzi@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 19:21:48 by zharzi            #+#    #+#             */
/*   Updated: 2022/10/20 23:27:35 by zharzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

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
	paths = (char **)malloc(sizeof(char *) * (len + 1));////////////////
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
