/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_validpath.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zharzi <zharzi@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/30 01:08:30 by zharzi            #+#    #+#             */
/*   Updated: 2022/10/28 12:34:57 by zharzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
/*
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
	{
		if (data->cursor == 1)
		{
			if ((!access(data->argv[0], F_OK) && access(data->argv[0], R_OK)) \
				|| (!data->infile && access(data->argv[0], F_OK)))
				return (NULL);
		}
					else if (data->cursor == data->ac - 2 && (!access(data->outfile, F_OK) \
						&& access(data->outfile, W_OK)))
						return (NULL);
		return (data->fullpaths[i]);
	}
	else if (data->cursor != 1 && data->cursor != data->ac -2)
		ft_cmd_not_found(data->cmd[0]);
	return (NULL);
}
*/
