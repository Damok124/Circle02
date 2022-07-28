/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strs_to_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zharzi <zharzi@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 23:45:28 by zharzi            #+#    #+#             */
/*   Updated: 2022/07/29 00:36:30 by zharzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	*ft_strs_to_tab(char **strs)
{
	int	*tab;
	int	i;
	int	x;

	i = -1;
	x = 0;
	while (strs[++i])
		x++;
	i = -1;
	tab = (int *)malloc(sizeof(char) * x);
	while (strs[++i])
	{
		if (ft_check_int(strs[i]))
			tab[i] = ft_atoi(strs[i]);
		else
		{
			if (tab)
				ft_true_free(tab);
			return (NULL);
		}
	}
	return (tab);
}
