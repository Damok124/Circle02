/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zharzi <zharzi@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 15:53:26 by zharzi            #+#    #+#             */
/*   Updated: 2022/08/07 23:00:37 by zharzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	t_count	c;
	char	*str;

	c.i = 0;
	c.j = 0;
	c.k = (size_t)ft_strlen(s1) + (size_t)ft_strlen(s2);
	str = (char *)malloc(sizeof(char) *(c.k + 1));
	if (!str)
		return (NULL);
	while (s1 && s1[c.i])
	{
		str[c.i + c.j] = s1[c.i];
		c.i++;
	}
	while (s2 && s2[c.j])
	{
		str[c.i + c.j] = s2[c.j];
		c.j++;
	}
	str[c.i + c.j] = '\0';
	return (str);
}
