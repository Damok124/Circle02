/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move_rr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zharzi <zharzi@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/24 04:58:04 by zharzi            #+#    #+#             */
/*   Updated: 2022/08/12 10:52:59 by zharzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pswap.h"

void	ft_move_rr(t_list **astack, t_list **bstack, t_control *values)
{
	if (*astack && (*astack)->next && *bstack && (*bstack)->next)
	{
		ft_ra_details(astack);
		ft_rb_details(bstack);
		if (values->pop_a)
		{
			values->pop_a--;
			values->pop_ea++;
		}
		if (values->pop_b)
		{
			values->pop_b--;
			values->pop_eb++;
		}
		ft_printf("rr\n");
	}
}
