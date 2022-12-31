/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_quartet.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zharzi <zharzi@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/31 11:58:22 by zharzi            #+#    #+#             */
/*   Updated: 2022/12/31 12:34:21 by zharzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pswap.h"

void	ft_sort_quartet(t_stack **top_a, t_stack **top_b)
{
	t_stack	*tmp;

	tmp = ft_get_last_elem(*top_a);
	if (!ft_check_stack_order(*top_a, ASCENDING) && tmp->index == 0)
		ft_move_rra(top_a, PRINT_OK);
	while (!ft_check_stack_order(*top_a, ASCENDING) && (*top_a)->index != 0)
	{
		ft_move_ra(top_a, PRINT_OK);
		tmp = ft_get_last_elem(*top_a);
	}
	if (!ft_check_stack_order(*top_a, ASCENDING) && (*top_a)->index == 0)
	{
		ft_move_pb(top_a, top_b, PRINT_OK);
		ft_sort_trio(top_a);
	}
}
