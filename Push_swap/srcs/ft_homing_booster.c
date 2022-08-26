/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_homing_booster.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zharzi <zharzi@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/26 17:30:53 by zharzi            #+#    #+#             */
/*   Updated: 2022/08/26 17:32:15 by zharzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pswap.h"

int	ft_homing_booster(t_list **astack, t_list **bstack, t_control *val)
{
	t_list	*tmp;
	int		check;

	check = 0;
	if (*astack)
	{
		tmp = ft_lstlast(*astack);
		while (val->ac > 4 && tmp && !ft_is_lock(tmp, astack, val) \
		&& tmp->index <= val->firstthird)
		{
			ft_move_rra(astack, val);
			ft_swap_top_test(astack, bstack, val);
			check = 1;
			tmp = ft_lstlast(*astack);
		}
		ft_put_end(astack, val, 1);
		if (!val->lock && (*astack)->index == val->max)
			ft_move_ra(astack, val);
	}
	return (check);
}
