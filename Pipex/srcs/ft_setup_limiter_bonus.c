/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_setup_limiter_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zharzi <zharzi@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/09 21:39:55 by zharzi            #+#    #+#             */
/*   Updated: 2022/10/16 18:15:45 by zharzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

char	*ft_setup_limiter(const char *src)
{
	size_t	i;
	size_t	size;
	char	*dst;

	i = 0;
	size = ft_strlen(src);
	dst = ft_calloc(size + 2, sizeof(char));
	if (size == 0)
		return (NULL);
	while (src[i] && i < (size))
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\n';
	dst[i + 1] = '\0';
	return (dst);
}
