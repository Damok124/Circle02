/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pswap_intfinder.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zharzi <zharzi@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 00:02:21 by zharzi            #+#    #+#             */
/*   Updated: 2022/08/04 00:04:57 by zharzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pswap.h"

int	ft_pswap_intfinder(char **av)
{
	t_count	c;

	c.i = -1;
	c.j = -1;
	c.x = 0;
	while (av[++c.i])
	{
		while (av[c.i][++c.j] != '\0')
			if (ft_isdigit(av[c.i][c.j]))
				c.x++;
		if (!c.x)
			return (0);
		c.x = 0;
		c.j = -1;
	}
	return (1);
}
