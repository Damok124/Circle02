/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_quintet.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zharzi <zharzi@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/31 11:58:22 by zharzi            #+#    #+#             */
/*   Updated: 2022/12/31 12:34:35 by zharzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pswap.h"

void	ft_sort_quintet(t_stack **top_a, t_stack **top_b)
{
	t_stack	*tmp;
	int		n;

	n = 0;
	tmp = ft_get_last_elem(*top_a);
	while (n != 2 && !ft_check_stack_order(*top_a, ASCENDING))
	{
		if (tmp->index == 0 || tmp->index == 1)
			ft_move_rra(top_a, PRINT_OK);
		if ((*top_a)->index == 0 || (*top_a)->index == 1)
		{
			ft_move_pb(top_a, top_b, PRINT_OK);
			n++;
		}
		else
			ft_move_ra(top_a, PRINT_OK);
		tmp = ft_get_last_elem(*top_a);
	}
	if (!ft_check_stack_order(*top_b, DESCENDING))
		ft_move_sb(top_b, PRINT_OK);
	ft_sort_trio(top_a);
}
