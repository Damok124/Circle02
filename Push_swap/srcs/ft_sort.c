/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zharzi <zharzi@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/31 11:58:22 by zharzi            #+#    #+#             */
/*   Updated: 2022/12/31 12:47:55 by zharzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pswap.h"

void	ft_sort(t_stack **top_a, t_stack **top_b, int *ratio)
{
	int	i;

	i = -1;
	if ((*top_a)->size <= 100)
	{
		ft_chunk_a_in_b(top_a, top_b);
		ft_solve_chunks(top_a, top_b);
	}
	else
	{
		while (i < 8)
			ft_thirds_a_in_b(top_a, top_b, ft_stack_len(top_a), ratio[++i]);
		ft_solve_all(top_a, top_b);
	}
}
