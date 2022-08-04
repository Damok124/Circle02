/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pswap_join.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zharzi <zharzi@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 00:02:23 by zharzi            #+#    #+#             */
/*   Updated: 2022/08/04 00:05:54 by zharzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pswap.h"

char	*ft_pswap_join(char **av)
{
	t_count	c;
	char	*full;
	char	*tmp;

	c.i = -1;
	c.a = 0;
	full = NULL;
	while (av && av[++c.i])
	{
		tmp = full;
		full = ft_strjoin(full, av[c.i]);
		if (tmp)
			ft_true_free(tmp);
		tmp = full;
		full = ft_strjoin(full, " ");
		if (tmp)
			ft_true_free(tmp);
		c.a++;
	}
	return (full);
}
