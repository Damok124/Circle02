/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_data.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zharzi <zharzi@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 20:09:11 by zharzi            #+#    #+#             */
/*   Updated: 2022/11/01 20:09:12 by zharzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

t_data	ft_init_data(int ac, char **argv, char **env)
{
	t_data	data;

	data.ac = ac;
	data.argv = argv;
	data.env = env;
	return (data);
}
