/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_valid_sign.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zharzi <zharzi@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/31 11:58:22 by zharzi            #+#    #+#             */
/*   Updated: 2022/12/31 15:32:16 by zharzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pswap_bonus.h"

int	ft_check_valid_sign(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
	{
		if (ft_strchr("+-", str[i]))
		{
			i++;
			if (!str[i] || !ft_strchr("0123456789", str[i]))
				return (0);
		}
		i++;
	}
	i = 0;
	while (str[i])
	{
		if (ft_strchr("+-", str[i]) && i && ft_strchr("0123456789", str[i - 1]))
			return (0);
		i++;
	}
	return (1);
}
