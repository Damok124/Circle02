/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_infile_permission_bonus.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zharzi <zharzi@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 00:00:02 by zharzi            #+#    #+#             */
/*   Updated: 2022/11/08 00:10:30 by zharzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

int	ft_infile_permission(char *filename)
{
	char	*msg;

	if (!access(filename, F_OK) && access(filename, R_OK))
	{
		msg = ft_strjoin("pipex: ", filename);
		perror(msg);
		ft_true_free((void **)&msg);
		return (0);
	}
	return (1);
}
