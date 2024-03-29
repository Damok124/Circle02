/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_drain_b.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zharzi <zharzi@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/31 11:58:22 by zharzi            #+#    #+#             */
/*   Updated: 2022/12/31 19:57:23 by zharzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pswap.h"

void	ft_drain_b(t_stack **astack, t_stack **bstack)
{
	while (*bstack)
	{
		ft_move_pa(astack, bstack, PRINT_OK);
		if (ft_swap_test_a(astack))
			ft_move_sa(astack, PRINT_OK);
	}
}
