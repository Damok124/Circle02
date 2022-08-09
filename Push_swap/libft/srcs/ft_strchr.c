/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zharzi <zharzi@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/10 00:15:02 by zharzi            #+#    #+#             */
/*   Updated: 2022/08/07 22:57:30 by zharzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	size_t	i;
	char	*p;

	i = 0;
	while (c > 127)
		c -= 128;
	p = (char *)s;
	while (i <= ft_strlen(s))
	{
		if (p[i] == c)
			return (&p[i]);
		i++;
	}
	return (NULL);
}
