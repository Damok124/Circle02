/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_strs_int.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zharzi <zharzi@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/24 13:46:22 by zharzi            #+#    #+#             */
/*   Updated: 2022/07/24 13:55:07 by zharzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_check_strs_int(char **str)
{
	size_t	i;
	size_t	len;

	i = 0;
	len = ft_chartab_len(str);
	if (len == 0)
		return (0);
	while (i < len)
	{
		if (!ft_check_int(str[i]))
			return (0);
		i++;
	}
	return (1);
}
