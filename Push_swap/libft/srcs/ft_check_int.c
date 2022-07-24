/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_int.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zharzi <zharzi@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/24 10:50:12 by zharzi            #+#    #+#             */
/*   Updated: 2022/07/25 00:05:04 by zharzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_check_int(char *str1)
{
	char	*str2;
	int		val;
	size_t	lstr1;
	size_t	lstr2;

	if (str1)
	{
		val = ft_atoi(str1);
		str2 = ft_itoa(val);
		lstr1 = ft_strlen(str1);
		lstr2 = ft_strlen(str2);
		if (lstr1 != lstr2 || ft_strncmp(str1, str2, lstr1))
		{
			ft_true_free(str2);
			return (0);
		}
		ft_true_free(str2);
	}
	return (1);
}
