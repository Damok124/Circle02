/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_end.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zharzi <zharzi@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/24 17:26:41 by zharzi            #+#    #+#             */
/*   Updated: 2022/08/24 17:56:10 by zharzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pswap.h"

void	ft_put_end(t_list **astack, t_control *val, int position)
{
	t_list	*tmp;
	int		series;

	series = ft_series_length(*astack, -1, position);
	tmp = ft_lst_find_one(*astack, position + series - 2);
	if (tmp->index == val->ac)
	{
		while (series > 0)
		{
			ft_move_ra(astack, val);
			series--;
		}
	}
}
