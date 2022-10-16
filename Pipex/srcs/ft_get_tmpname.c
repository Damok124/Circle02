/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_tmpname.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zharzi <zharzi@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 18:29:55 by zharzi            #+#    #+#             */
/*   Updated: 2022/10/16 21:02:04 by zharzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

int	ft_check_tmpname(char *tmpname)
{
	if (tmpname && access(tmpname, F_OK) == -1)
		return (1);
	return (0);
}

char	*ft_get_tmpname(char **basename)
{
	char	*tmpname;
	char	*nb;
	int		test;
	int		max;
	int		i;

	i = 1;
	test = 0;
	max = 100000000;
	tmpname = NULL;
	while (!test && i < max)
	{
		nb = ft_itoa(-i);
		tmpname = ft_strjoin(*basename, nb);
		test = ft_check_tmpname(tmpname);
		if (!test)
			ft_true_free((void **)&tmpname);
		i++;
	}
	ft_true_free((void **)basename);
	return (tmpname);
}
/*
char	*ft_get_tmpname(char *basename)
{
	char	*tmpname;
	char	*nb;
	int		test;
	int		max;
	int		i;

	i = 1;
	test = 0;
	max = 100000000;
	tmpname = NULL;
	while (!test && i < max)
	{
		nb = ft_itoa(-i);
		tmpname = ft_strjoin(basename, nb);
		test = ft_check_tmpname(tmpname);
		if (!test)
			ft_true_free((void **)&tmpname);
		i++;
	}
	return (tmpname);
}
*/
