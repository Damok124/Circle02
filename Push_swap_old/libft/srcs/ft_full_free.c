/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_full_free.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zharzi <zharzi@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/02 01:23:40 by zharzi            #+#    #+#             */
/*   Updated: 2022/08/26 16:38:32 by zharzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_full_free(void **tobefreed)
{
	int	i;

	i = -1;
	while (tobefreed && tobefreed[++i])
		ft_true_free(tobefreed[i]);
	ft_true_free(tobefreed);
}
