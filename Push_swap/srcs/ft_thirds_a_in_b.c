/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_thirds_a_in_b.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zharzi <zharzi@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/31 11:58:22 by zharzi            #+#    #+#             */
/*   Updated: 2022/12/31 12:38:22 by zharzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pswap.h"

void	ft_thirds_a_in_b(t_stack **top_a, t_stack **top_b, int size, int ratio)
{
	static int	moves;
	int			cap;
	int			midcap;

	cap = size * ratio / 100 + moves;
	midcap = size * ratio / 100 / 2 + moves;
	while (moves < cap)
	{
		if ((*top_a)->index <= cap)
		{
			ft_move_pb(top_a, top_b, PRINT_OK);
			if ((*top_b)->index <= midcap)
				ft_move_rb(top_b, PRINT_OK);
			moves++;
		}
		else
			ft_move_ra(top_a, PRINT_OK);
	}
}
