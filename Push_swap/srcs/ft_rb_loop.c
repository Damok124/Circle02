/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rb_loop.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zharzi <zharzi@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/31 11:58:22 by zharzi            #+#    #+#             */
/*   Updated: 2022/12/31 12:36:32 by zharzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pswap.h"

void	ft_rb_loop(t_stack **top_a, t_stack **top_b, int target, int *bonus)
{
	while ((*top_b)->index != target)
	{
		if ((*top_b)->index == target - 1)
		{
			ft_move_pa(top_a, top_b, PRINT_OK);
			*bonus += 1;
		}
		else
			ft_move_rb(top_b, PRINT_OK);
	}
}
