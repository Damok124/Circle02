/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_dup_int.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zharzi <zharzi@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 00:25:52 by zharzi            #+#    #+#             */
/*   Updated: 2022/08/26 16:38:23 by zharzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_check_dup_int(int len, int *tab)
{
	int	i;

	i = 0;
	while (tab && i < len - 1)
	{
		if (tab[i] == tab[i + 1])
			return (0);
		i++;
	}
	return (1);
}
