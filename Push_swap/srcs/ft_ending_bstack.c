/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ending_bstack.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zharzi <zharzi@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/07 17:29:50 by zharzi            #+#    #+#             */
/*   Updated: 2022/08/16 17:07:55 by zharzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pswap.h"

void	ft_ending_bstack(t_list **astack, t_list **bstack, t_control *val)
{
	ft_printf("\tending bstack, multi pa\n");
	while (*bstack)
		ft_move_pa(astack, bstack, val);
}
