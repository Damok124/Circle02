/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_data.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zharzi <zharzi@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 14:38:40 by zharzi            #+#    #+#             */
/*   Updated: 2022/10/20 14:48:38 by zharzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_init_data(t_data *data, int ac, char **argv, char **env)
{
	data->cursor = 0;
	data->ac = ac - 1;
	data->infile = argv[1];
	data->outfile = argv[ac - 1];
	data->argv = argv + 1;
	data->env = env;
}
