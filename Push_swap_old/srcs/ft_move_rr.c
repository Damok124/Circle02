/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move_rr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zharzi <zharzi@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/24 04:58:04 by zharzi            #+#    #+#             */
/*   Updated: 2022/08/22 15:55:26 by zharzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pswap.h"

void	ft_move_rr(t_list **astack, t_list **bstack, t_control *val)
{
	if (*astack && (*astack)->next && *bstack && (*bstack)->next)
	{
		ft_ra_details(astack);
		ft_rb_details(bstack);
		if (val->pop_a)
		{
			val->pop_a--;
			val->pop_ea++;
		}
		if (val->pop_b)
		{
			val->pop_b--;
			val->pop_eb++;
			val->total++;
		}
		ft_printf("rr\n");
	}
}
