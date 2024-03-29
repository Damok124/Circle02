/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_fullpaths.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zharzi <zharzi@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 19:51:25 by zharzi            #+#    #+#             */
/*   Updated: 2022/11/01 19:51:27 by zharzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

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
