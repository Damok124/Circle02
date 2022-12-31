/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pswap_args_check.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zharzi <zharzi@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/31 11:58:22 by zharzi            #+#    #+#             */
/*   Updated: 2022/12/31 15:31:51 by zharzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pswap_bonus.h"

int	ft_pswap_args_check(char **argv)
{
	int	i;

	i = 0;
	while (argv[i])
	{
		if (!ft_check_valid_char_only(argv[i]))
			return (0);
		if (!ft_check_valid_sign(argv[i]))
			return (0);
		if (!ft_check_empty_arg(argv[i]))
			return (0);
		if (!ft_check_overflow(argv[i]))
			return (0);
		i++;
	}
	return (1);
}
