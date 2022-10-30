/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_data_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zharzi <zharzi@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 14:38:38 by zharzi            #+#    #+#             */
/*   Updated: 2022/10/20 23:56:23 by zharzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	ft_init_data_b(t_data *data, int ac, char **argv, char **env)
{
	data->cursor = 0;
	data->ac = ac - 1;
	data->infile = NULL;
	data->outfile = argv[ac - 1];
	data->argv = argv + 1;
	data->env = env;
}
