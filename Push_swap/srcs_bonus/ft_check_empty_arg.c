/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_empty_arg.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zharzi <zharzi@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/31 11:58:22 by zharzi            #+#    #+#             */
/*   Updated: 2022/12/31 15:32:21 by zharzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pswap_bonus.h"

int	ft_check_empty_arg(char *str)
{
	char	*tmp;

	tmp = NULL;
	if (!str)
		return (0);
	tmp = ft_strtrim(str, " \b\t\n\v\f\r");
	if (!tmp[0])
	{
		ft_true_free((void **)&tmp);
		return (0);
	}
	ft_true_free((void **)&tmp);
	return (1);
}
