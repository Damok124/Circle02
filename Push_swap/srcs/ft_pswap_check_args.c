/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pswap_check_args.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zharzi <zharzi@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 00:02:18 by zharzi            #+#    #+#             */
/*   Updated: 2022/08/26 16:38:41 by zharzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pswap.h"

int	ft_pswap_check_args(int *ac, char *full)
{
	int	i;

	i = 0;
	*ac = 0;
	while (full[i])
	{
		if (full[i] && (full[i] == ' ' || ((full[i] == '+' || \
		full[i] == '-') && (full[i + 1] && ft_isdigit(full[i + 1])))))
			i++;
		else if (full[i] && ft_isdigit(full[i]))
		{
			*ac += 1;
			while (full[i] && ft_isdigit(full[i]))
				i++;
			if (full[i] && full[i] != ' ')
				return (0);
		}
		else
			return (0);
	}
	return (1);
}
