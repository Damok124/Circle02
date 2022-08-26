/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_moves_backward.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zharzi <zharzi@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/11 11:14:00 by zharzi            #+#    #+#             */
/*   Updated: 2022/08/26 17:54:27 by zharzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pswap.h"

void	ft_get_from_ea(t_list **astack, t_control *val)
{
	ft_move_rra(astack, val);
}

void	ft_get_from_b(t_list **astack, t_list **bstack, t_control *val)
{
	ft_move_pa(astack, bstack, val);
}

void	ft_get_from_eb(t_list **astack, t_list **bstack, t_control *val)
{
	ft_move_rrb(bstack, val);
	ft_move_pa(astack, bstack, val);
}
