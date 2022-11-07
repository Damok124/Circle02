/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_goodpath_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zharzi <zharzi@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 23:59:52 by zharzi            #+#    #+#             */
/*   Updated: 2022/11/08 00:07:54 by zharzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

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
