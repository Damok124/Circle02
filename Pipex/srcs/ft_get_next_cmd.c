/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_next_cmd.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zharzi <zharzi@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/02 00:31:05 by zharzi            #+#    #+#             */
/*   Updated: 2022/10/02 00:33:00 by zharzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_get_next_cmd(t_data *data)
{
	data->cmd = ft_parse_cmd(data->argv[data->cursor]);
	data->paths = ft_get_paths(data->env);
	data->fullpaths = ft_get_fullpaths(data->paths, data->cmd[0]);
	data->validpath = ft_get_validpath(data);
	data->cursor += 1;
}
