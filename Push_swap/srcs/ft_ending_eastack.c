/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ending_eastack.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zharzi <zharzi@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/17 22:40:36 by zharzi            #+#    #+#             */
/*   Updated: 2022/08/17 22:40:39 by zharzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pswap.h"

void	ft_ending_eastack(t_list **astack, t_control *val)
{
	ft_printf("\tending eastack, multi rra\n");
	while (val->pop_ea)
		ft_move_rra(astack, val);
}
