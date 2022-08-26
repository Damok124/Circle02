/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pswap_view.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zharzi <zharzi@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/17 21:27:07 by zharzi            #+#    #+#             */
/*   Updated: 2022/08/26 14:07:34 by zharzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pswap.h"

void	ft_pswap_view(t_list **astack, t_list **bstack, t_control *val)
{
	int	i;

	i = 0;
	ft_printf("\n");
	ft_show_values(*val);
	ft_show_stacks(astack, bstack, val);
	ft_printf("original : ");
	while (val->argv[i])
	{
		ft_printf("%s ", val->argv[i]);
		i++;
	}
	ft_printf("\n");
	ft_printf("-------------------------\n");
}
