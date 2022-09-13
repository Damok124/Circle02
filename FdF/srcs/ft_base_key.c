/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_base_key.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zharzi <zharzi@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 17:51:36 by zharzi            #+#    #+#             */
/*   Updated: 2022/09/12 17:51:51 by zharzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

char	ft_base_key(int *tab, int key)
{
	int	i;
	int	x;

	i = 0;
	x = 0;
	while (i < 16)
	{
		if (key == tab[i])
			x = i;
		i++;
	}
	if (x < 10)
		return (x + '0');
	else
		x %= 10;
	return (x + 'A');
}
