/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lock_elem.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zharzi <zharzi@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/17 09:27:43 by zharzi            #+#    #+#             */
/*   Updated: 2022/08/30 14:52:11 by zharzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pswap.h"

int	ft_lock_elem(t_list **astack, t_control **val)
{
	t_list	*tmp1;

	if ((*val)->pop_a && (*val)->lock)
	{
		tmp1 = *astack;
		while (tmp1->next && !ft_is_lock(tmp1->next, astack, *val))
			tmp1 = tmp1->next;
		if (ft_is_lock(tmp1->next, astack, *val))
		{
			if (ft_test_index(tmp1, tmp1->next) == -1)
			{
				(*val)->pop_a--;
				(*val)->lock++;
				(*val)->max--;
				return (1);
			}
		}
	}
	return (0);
}
