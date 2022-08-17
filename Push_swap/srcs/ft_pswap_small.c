/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pswap_small.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zharzi <zharzi@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/17 22:44:06 by zharzi            #+#    #+#             */
/*   Updated: 2022/08/17 22:44:15 by zharzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pswap.h"

void	ft_pswap_small(t_list **astack, t_list **bstack, t_control *val)
{
	while (!ft_pswap_final(astack, bstack, val))
	{
		if ((*astack)->index > val->lastthird)
		{
			ft_push_to_ea(astack, val);
			if ((*astack)->index <= val->firstthird)
				ft_swap_test(astack, bstack, val);
			ft_rotate_test(astack, bstack, val);
		}
		while (!ft_pswap_final(astack, bstack, val))
		{
			ft_swap_test(astack, bstack, val);
			ft_rotate_test(astack, bstack, val);
		}
	}
}
