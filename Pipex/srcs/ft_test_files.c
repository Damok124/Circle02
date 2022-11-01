/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_test_files.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zharzi <zharzi@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 20:08:02 by zharzi            #+#    #+#             */
/*   Updated: 2022/11/01 20:08:17 by zharzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	ft_test_files(char **argv, int ac)
{
	if (ft_such_file(argv[1]))
		ft_infile_permission(argv[1]);
	if (!ft_outfile_permission(argv[ac - 1]))
		return (0);
	return (1);
}
