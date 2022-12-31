/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_index.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zharzi <zharzi@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/31 11:58:22 by zharzi            #+#    #+#             */
/*   Updated: 2022/12/31 12:32:23 by zharzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pswap.h"

int	ft_get_index(int value, int *ordered)
{
	int	i;

	i = 0;
	while (ordered)
	{
		if (ordered[i] == value)
			return (i);
		i++;
	}
	return (-1);
}
