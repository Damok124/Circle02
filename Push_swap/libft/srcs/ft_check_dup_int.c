/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_dup_int.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zharzi <zharzi@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 00:25:52 by zharzi            #+#    #+#             */
/*   Updated: 2022/08/04 03:59:22 by zharzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_check_dup_int(int len, int *tab)
{
	t_count	c;

	c.i = 0;
	while (tab && c.i < len - 1)
	{
		if (tab[c.i] == tab[c.i + 1])
			return (0);
		c.i++;
	}
	return (1);
}
