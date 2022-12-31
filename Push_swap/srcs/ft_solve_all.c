/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_solve_all.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zharzi <zharzi@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/31 11:58:22 by zharzi            #+#    #+#             */
/*   Updated: 2022/12/31 12:37:09 by zharzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pswap.h"

void	ft_solve_all(t_stack **top_a, t_stack **top_b)
{
	int	bonus;
	int	target;

	target = (*top_b)->size -1;
	while (*top_b)
	{
		bonus = 0;
		if (ft_up_cost(top_b, target) <= ft_down_cost(top_b, target))
			ft_rb_loop(top_a, top_b, target, &bonus);
		else if (ft_up_cost(top_b, target) > ft_down_cost(top_b, target))
			ft_rrb_loop(top_a, top_b, target, &bonus);
		ft_move_pa(top_a, top_b, PRINT_OK);
		bonus++;
		if (ft_swap_test_a(top_a))
			ft_move_sa(top_a, PRINT_OK);
		target = target - bonus;
	}
}
