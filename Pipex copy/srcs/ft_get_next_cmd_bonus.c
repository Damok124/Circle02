/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_next_cmd_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zharzi <zharzi@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 20:22:25 by zharzi            #+#    #+#             */
/*   Updated: 2022/10/20 23:25:45 by zharzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	ft_get_next_cmd_b(t_data *data)
{
	data->cmd = ft_parse_cmd(data->argv[data->cursor]);
	if (*data->cmd)
	{
		data->paths = ft_get_paths(data->env);
		data->fullpaths = ft_get_fullpaths(data->paths, data->cmd[0]);
		data->validpath = ft_get_validpath_b(data);
	}
	else
	{
		ft_cmd_not_found("");
		data->paths = ft_get_paths(data->env);
		data->fullpaths = ft_get_fullpaths(data->paths, data->cmd[0]);
		data->validpath = NULL;
	}
	data->cursor += 1;
}
