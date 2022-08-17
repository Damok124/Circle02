/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_moves_forward.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zharzi <zharzi@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/11 11:09:03 by zharzi            #+#    #+#             */
/*   Updated: 2022/08/16 14:51:10 by zharzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pswap.h"

void	ft_push_to_ea(t_list **astack, t_control *values)
{
	ft_move_ra(astack, values);
}

void	ft_push_to_b(t_list **astack, t_list **bstack, t_control *values)
{
	ft_move_pb(astack, bstack, values);
}

void	ft_push_to_eb(t_list **astack, t_list **bstack, t_control *values)
{
	ft_move_pb(astack, bstack, values);
	if (*bstack && (*bstack)->next && \
	(*bstack)->index - 1 != (*bstack)->next->index)
		ft_move_rb(bstack, values);
	else
	{
		values->pop_b--;
		values->pop_eb++;
	}
}
