/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pattern_count.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zharzi <zharzi@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 18:34:59 by zharzi            #+#    #+#             */
/*   Updated: 2022/10/11 18:35:11 by zharzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

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
