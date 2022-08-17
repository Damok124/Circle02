/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pswap_distri.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zharzi <zharzi@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 14:20:16 by zharzi            #+#    #+#             */
/*   Updated: 2022/08/17 21:14:24 by zharzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pswap.h"

void	ft_pswap_distri(t_list **astack, t_list **bstack, t_control *val)
{
	ft_printf("\tpswap distri\n");
	if ((*astack)->index > val->lastthird)
		ft_push_to_ea(astack, val);
	else if ((*astack)->index <= val->firstthird)
		ft_push_to_eb(astack, bstack, val);
	else
		ft_push_to_b(astack, bstack, val);
	ft_pswap_view(astack, bstack, val);
}
