/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_trio.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zharzi <zharzi@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/31 11:58:22 by zharzi            #+#    #+#             */
/*   Updated: 2022/12/31 12:34:08 by zharzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pswap.h"

void	ft_sort_trio(t_stack **top_a)
{
	t_stack	*tmp;

	if ((*top_a)->index == (*top_a)->size - 1)
		ft_move_ra(top_a, PRINT_OK);
	tmp = ft_get_last_elem(*top_a);
	if (!ft_check_stack_order(*top_a, ASCENDING) && tmp->index != tmp->size - 1)
		ft_move_rra(top_a, PRINT_OK);
	tmp = ft_get_last_elem(*top_a);
	if (!ft_check_stack_order(*top_a, ASCENDING) && tmp->index == tmp->size - 1)
		ft_move_sa(top_a, PRINT_OK);
}
