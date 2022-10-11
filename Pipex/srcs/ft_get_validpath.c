/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_validpath.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zharzi <zharzi@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/30 01:08:30 by zharzi            #+#    #+#             */
/*   Updated: 2022/10/05 22:26:07 by zharzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*ft_get_validpath(t_data *data)
{
	int	i;

	i = 0;
	if (!access(data->cmd[0], F_OK | X_OK))
		return (data->cmd[0]);
	while (data->fullpaths && data->fullpaths[i] && access(data->fullpaths[i], \
		F_OK | X_OK))
		i++;
	if (data->fullpaths && data->fullpaths[i])
		return (data->fullpaths[i]);
	return (NULL);
}
