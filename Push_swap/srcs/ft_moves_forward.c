/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_moves_forward.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zharzi <zharzi@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/11 11:09:03 by zharzi            #+#    #+#             */
/*   Updated: 2022/08/19 22:30:12 by zharzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pswap.h"

void	ft_push_to_ea(t_list **astack, t_list **bstack, t_control *val)
{
	ft_lock_elem(astack, bstack, &val);
	ft_move_ra(astack, val);
}

void	ft_push_to_b(t_list **astack, t_list **bstack, t_control *val)
{
	ft_lock_elem(astack, bstack, &val);
	ft_move_pb(astack, bstack, val);
}

void	ft_push_to_eb(t_list **astack, t_list **bstack, t_control *val)
{
	ft_lock_elem(astack, bstack, &val);
	ft_move_pb(astack, bstack, val);
	if (*bstack && (*bstack)->next && \
	(*bstack)->index - 1 != (*bstack)->next->index)
		ft_move_rb(bstack, val);
	else
	{
		val->pop_b--;
		val->pop_eb++;
	}
}
