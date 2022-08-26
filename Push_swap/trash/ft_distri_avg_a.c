/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_distri_avg_a.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zharzi <zharzi@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/20 14:44:32 by zharzi            #+#    #+#             */
/*   Updated: 2022/08/20 14:48:56 by zharzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pswap.h"

void	ft_distri_avg_a(t_list **astack, t_list **bstack, t_control *val)
{
	int	avg;

	avg = 0;
	ft_printf("\tdistri avg a\n");
	if (val->pop_a)
	{
		avg = ft_find_lstavg(bstack);
		if ((*astack)->index >= avg)
			ft_push_to_b(astack, bstack, val);
		else
			ft_push_to_eb(astack, bstack, val);
		ft_swap_top_test(astack, bstack, val);
	}
}
