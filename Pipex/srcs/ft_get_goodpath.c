/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_goodpath.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zharzi <zharzi@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 19:50:58 by zharzi            #+#    #+#             */
/*   Updated: 2022/11/01 19:51:01 by zharzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

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
