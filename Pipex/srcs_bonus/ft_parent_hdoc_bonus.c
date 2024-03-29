/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parent_hdoc_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zharzi <zharzi@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 00:00:11 by zharzi            #+#    #+#             */
/*   Updated: 2022/11/08 00:14:24 by zharzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	ft_parent_hdoc(t_data *data, char **cmd_args, char **validpaths, int i)
{
	cmd_args = ft_split(data->argv[i + 3], ' ');
	ft_append_to_outfile(validpaths, i, cmd_args, data);
}
