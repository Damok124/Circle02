/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_error_msg.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zharzi <zharzi@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 15:20:06 by zharzi            #+#    #+#             */
/*   Updated: 2022/10/21 14:23:43 by zharzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	ft_print_error_msg(t_data *data)
{
	int	test;

	test = -1;
	if (!access(data->infile, F_OK) && access(data->infile, R_OK))
	{
		ft_err_msg(data->infile, ": Permission denied\n");
		test = 0;
	}
	else if (!data->infile && access(data->infile, F_OK))
	{
		ft_err_msg(data->argv[0], ": No such file or directory\n");
		test = 1;
	}
	if (!access(data->outfile, F_OK) && access(data->outfile, W_OK))
	{
		ft_err_msg(data->outfile, ": Permission denied\n");
		test = 0;
	}
	return (test);
}
