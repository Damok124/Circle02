/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pswap_check_args.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zharzi <zharzi@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 00:02:18 by zharzi            #+#    #+#             */
/*   Updated: 2022/08/04 00:05:14 by zharzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pswap.h"

int	ft_pswap_check_args(int *ac, char *full)
{
	t_count	c;

	c.i = 0;
	*ac = 0;
	while (full[c.i])
	{
		if (full[c.i] && (full[c.i] == ' ' || ((full[c.i] == '+' || \
		full[c.i] == '-') && (full[c.i + 1] && ft_isdigit(full[c.i + 1])))))
			c.i++;
		else if (full[c.i] && ft_isdigit(full[c.i]))
		{
			*ac += 1;
			while (full[c.i] && ft_isdigit(full[c.i]))
				c.i++;
			if (full[c.i] && full[c.i] != ' ')
				return (0);
		}
		else
			return (0);
	}
	return (1);
}
