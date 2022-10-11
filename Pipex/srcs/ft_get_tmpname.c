/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_tmpname.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zharzi <zharzi@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 18:29:55 by zharzi            #+#    #+#             */
/*   Updated: 2022/10/11 18:31:31 by zharzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	ft_check_tmpname(char *tmpname)
{
	if (tmpname && access(tmpname, F_OK) == -1)
		return (1);
	return (0);
}

int	ft_pattern_count(char *basename)
{
	int	len;
	int	pattern;
	int	i;

	pattern = 0;
	len = ft_strlen(basename);
	i = len - 1;
	while (len && i >= 0 && basename[i] == basename[len - 1])
	{
		pattern++;
		i--;
	}
	return (pattern);
}

char	*ft_join_iteration(char *basename, int pattern, int len, char *nb)
{
	int	delta;
	int	i;
	int	j;
	int	nblen;

	nblen = ft_strlen(nb);
	delta = len - pattern;
	j = 0;
	i = delta;
	while (j < nblen)
	{
		basename[i] = nb[j];
		i++;
		j++;
	}
	basename[i] = '\0';
	return (basename);
}

int	ft_max_value(int pattern)
{
	int	max;

	max = 0;
	if (pattern)
	{
		max = 10;
		while (--pattern)
			max *= 10;
	}
	return (max);
}

char	*ft_get_tmpname(char *basename, int pattern, int len)
{
	int		max;
	int		i;
	char	*nb;
	char	*tmpname;
	int		test;

	i = 1;
	test = 0;
	max = ft_max_value(pattern);
	tmpname = NULL;
	while (!test && i < max)
	{
		nb = ft_itoa(i);
		tmpname = ft_join_iteration(basename, pattern, len, nb);
		test = ft_check_tmpname(tmpname);
		if (!test)
			tmpname = NULL;
		i++;
	}
	return (tmpname);
}
