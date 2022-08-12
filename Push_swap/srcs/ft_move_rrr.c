/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move_rrr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zharzi <zharzi@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/24 05:00:08 by zharzi            #+#    #+#             */
/*   Updated: 2022/08/12 10:51:37 by zharzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pswap.h"

void	ft_move_rrr(t_list **astack, t_list **bstack, t_control *values)
{
	if (*astack && (*astack)->next && *bstack && (*bstack)->next)
	{
		ft_rra_details(astack);
		ft_rrb_details(bstack);
		if (values->pop_ea)
		{
			values->pop_a++;
			values->pop_ea--;
		}
		if (values->pop_eb)
		{
			values->pop_b++;
			values->pop_eb--;
		}
		ft_printf("rrr\n");
	}
}
