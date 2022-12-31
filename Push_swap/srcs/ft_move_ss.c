/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move_ss.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zharzi <zharzi@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/31 11:58:22 by zharzi            #+#    #+#             */
/*   Updated: 2022/12/31 12:54:43 by zharzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pswap.h"

void	ft_move_ss(t_stack **astack, t_stack **bstack, int print)
{
	if (*astack && (*astack)->next && *bstack && (*bstack)->next)
	{
		ft_move_sa(astack, NO_PRINT);
		ft_move_sb(bstack, NO_PRINT);
		if (print)
			ft_printf("ss\n");
	}
}
