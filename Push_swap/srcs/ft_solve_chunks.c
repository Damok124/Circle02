/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_solve_chunks.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zharzi <zharzi@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/31 11:58:22 by zharzi            #+#    #+#             */
/*   Updated: 2022/12/31 12:36:12 by zharzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pswap.h"

void	ft_solve_chunks(t_stack **top_a, t_stack **top_b)
{
	int	target;

	target = (*top_b)->size -1;
	while (*top_b)
	{
		if (ft_up_cost(top_b, target) <= ft_down_cost(top_b, target))
		{
			while ((*top_b)->index != target)
				ft_move_rb(top_b, PRINT_OK);
		}
		else if (ft_up_cost(top_b, target) > ft_down_cost(top_b, target))
		{
			while ((*top_b)->index != target)
				ft_move_rrb(top_b, PRINT_OK);
		}
		ft_move_pa(top_a, top_b, PRINT_OK);
		if (ft_swap_test_a(top_a))
			ft_move_sa(top_a, PRINT_OK);
		target = target - 1;
	}
}
