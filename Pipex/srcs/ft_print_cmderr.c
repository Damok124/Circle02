/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_cmderr.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zharzi <zharzi@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 20:08:44 by zharzi            #+#    #+#             */
/*   Updated: 2022/11/01 20:08:46 by zharzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_print_cmderr(char **validpaths, char **argv)
{
	char	**cmd_args;
	int		i;

	i = 0;
	while (validpaths && validpaths[i])
	{
		if (validpaths[i][0] == '\0')
		{
			cmd_args = ft_split(argv[i + 2], ' ');
			ft_cmd_not_found(cmd_args[0]);
			ft_full_free((void **)cmd_args);
		}
		i++;
	}
}
