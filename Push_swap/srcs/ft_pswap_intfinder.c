/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pswap_intfinder.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zharzi <zharzi@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 00:02:21 by zharzi            #+#    #+#             */
/*   Updated: 2022/08/26 16:38:49 by zharzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pswap.h"

int	ft_pswap_intfinder(char **av)
{
	int	i;
	int	j;
	int	x;

	i = -1;
	j = -1;
	x = 0;
	while (av[++i])
	{
		while (av[i][++j] != '\0')
			if (ft_isdigit(av[i][j]))
				x++;
		if (!x)
			return (0);
		x = 0;
		j = -1;
	}
	return (1);
}
