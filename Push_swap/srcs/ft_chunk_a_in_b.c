/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_chunk_a_in_b.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zharzi <zharzi@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/31 11:58:22 by zharzi            #+#    #+#             */
/*   Updated: 2022/12/31 12:47:39 by zharzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pswap.h"

void	ft_chunk_a_in_b(t_stack **top_a, t_stack **top_b)
{
	int	step;
	int	chunk_size;
	int	b_size;

	step = 1;
	b_size = 0;
	chunk_size = (*top_a)->size / 8;
	while (step != 9)
	{
		if ((*top_a)->index < chunk_size * (step + 1))
		{
			ft_move_pb(top_a, top_b, PRINT_OK);
			if ((*top_b)->index < (chunk_size * step))
				ft_move_rb(top_b, PRINT_OK);
			b_size++;
		}
		else
			ft_move_ra(top_a, PRINT_OK);
		if (b_size == chunk_size * (step + 1))
			step += 2;
		while (step == 9 && *top_a)
			ft_move_pb(top_a, top_b, PRINT_OK);
	}
}
