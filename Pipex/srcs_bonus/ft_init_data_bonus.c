/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_data_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zharzi <zharzi@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 00:00:06 by zharzi            #+#    #+#             */
/*   Updated: 2022/11/08 00:04:48 by zharzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

t_data	ft_init_data(int ac, char **argv, char **env)
{
	t_data	data;

	data.ac = ac;
	data.argv = argv;
	data.env = env;
	return (data);
}
