/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_btou.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zharzi <zharzi@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 00:03:20 by zharzi            #+#    #+#             */
/*   Updated: 2022/09/17 23:39:02 by zharzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

unsigned int	ft_btou(const char *nptr, char *base)
{
	unsigned int	ret;
	int				i;

	i = 0;
	ret = 0;
	if (nptr)
	{
		while ((*nptr >= '\t' && *nptr <= '\r') || *nptr == ' ')
			nptr++;
		if (*nptr == '+')
			nptr++;
		while (*nptr && ft_strchr(base, *nptr))
		{
			ret *= ft_strlen(base);
			while (base[i] != *nptr)
				i++;
			ret += i;
			i = 0;
			nptr++;
		}
	}
	return (ret);
}
