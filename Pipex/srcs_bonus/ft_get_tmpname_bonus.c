/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_tmpname_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zharzi <zharzi@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 23:59:55 by zharzi            #+#    #+#             */
/*   Updated: 2022/11/08 00:12:22 by zharzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

char	*ft_get_tmpname(char **basename)
{
	char	*tmpname;
	char	*nb;
	int		test;
	int		max;
	int		i;

	i = 1;
	test = 0;
	max = INT_MAX;
	tmpname = NULL;
	while (!test && i < max)
	{
		nb = ft_itoa(-i);
		tmpname = ft_strjoin(*basename, nb);
		test = ft_check_tmpname(tmpname);
		if (!test)
			ft_true_free((void **)&tmpname);
		ft_true_free((void **)&nb);
		i++;
	}
	ft_true_free((void **)basename);
	return (tmpname);
}
