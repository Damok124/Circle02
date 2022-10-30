/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_validpath_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zharzi <zharzi@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 23:24:26 by zharzi            #+#    #+#             */
/*   Updated: 2022/10/20 23:26:27 by zharzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

char	*ft_get_validpath_b(t_data *data)
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
	else
		ft_cmd_not_found(data->cmd[0]);
	return (NULL);
}
