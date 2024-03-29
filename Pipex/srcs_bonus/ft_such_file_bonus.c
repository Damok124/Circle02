/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_such_file_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zharzi <zharzi@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 00:00:18 by zharzi            #+#    #+#             */
/*   Updated: 2022/11/08 00:01:17 by zharzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

int	ft_such_file(char *filename)
{
	char	*msg;

	if (access(filename, F_OK))
	{
		msg = ft_strjoin("pipex: ", filename);
		perror(msg);
		ft_true_free((void **)&msg);
		return (0);
	}
	return (1);
}
