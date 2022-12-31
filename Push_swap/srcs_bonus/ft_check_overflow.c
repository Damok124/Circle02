/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_overflow.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zharzi <zharzi@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/31 11:58:22 by zharzi            #+#    #+#             */
/*   Updated: 2022/12/31 15:32:20 by zharzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pswap_bonus.h"

int	ft_check_overflow(char *str)
{
	char	**tmp;
	int		check;
	int		i;

	i = 0;
	check = 1;
	tmp = NULL;
	tmp = ft_split_set(str, " \b\t\n\v\f\r");
	while (tmp && tmp[i])
	{
		ft_atoi_safe(tmp[i], &check);
		if (!check)
		{
			ft_full_free((void **)tmp);
			return (0);
		}
		i++;
	}
	ft_full_free((void **)tmp);
	return (1);
}
