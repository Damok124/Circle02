/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move_rrr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zharzi <zharzi@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/24 05:00:08 by zharzi            #+#    #+#             */
/*   Updated: 2022/08/22 16:11:22 by zharzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pswap.h"

void	ft_move_rrr(t_list **astack, t_list **bstack, t_control *val)
{
	if (*astack && (*astack)->next && *bstack && (*bstack)->next)
	{
		ft_rra_details(astack);
		ft_rrb_details(bstack);
		if (val->pop_ea)
		{
			val->pop_a++;
			val->pop_ea--;
		}
		if (val->pop_eb)
		{
			val->pop_b++;
			val->pop_eb--;
		}
		val->total++;
		ft_printf("rrr\n");
	}
}
