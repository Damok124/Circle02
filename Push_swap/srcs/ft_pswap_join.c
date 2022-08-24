/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pswap_join.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zharzi <zharzi@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 00:02:23 by zharzi            #+#    #+#             */
/*   Updated: 2022/08/19 22:32:25 by zharzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pswap.h"

char	*ft_pswap_join(char **av)
{
	int		a;
	int		i;
	char	*full;
	char	*tmp;

	i = -1;
	a = 0;
	full = NULL;
	while (av && av[++i])
	{
		tmp = full;
		full = ft_strjoin(full, av[i]);
		if (tmp)
			ft_true_free(tmp);
		tmp = full;
		full = ft_strjoin(full, " ");
		if (tmp)
			ft_true_free(tmp);
		a++;
	}
	return (full);
}
