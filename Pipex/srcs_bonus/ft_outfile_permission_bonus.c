/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_outfile_permission_bonus.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zharzi <zharzi@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 00:00:08 by zharzi            #+#    #+#             */
/*   Updated: 2022/11/08 00:04:24 by zharzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

int	ft_outfile_permission(char *filename)
{
	char	*msg;

	if (!access(filename, F_OK) && access(filename, W_OK))
	{
		msg = ft_strjoin("pipex: ", filename);
		perror(msg);
		ft_true_free((void **)&msg);
		return (0);
	}
	return (1);
}
