/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_lock.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zharzi <zharzi@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/19 17:31:19 by zharzi            #+#    #+#             */
/*   Updated: 2022/08/19 17:43:00 by zharzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pswap.h"

int	ft_is_lock(t_list *elem, t_list **astack, t_control *val)
{
	t_list	*tmp;
	int		pop;

	pop = val->pop_a;
	tmp = *astack;
	if (pop && val->lock && tmp)
	{
		while (tmp && pop--)
			tmp = tmp->next;
		pop = val->lock;
		while (tmp && pop)
		{
			if (tmp == elem)
				return (1);
			tmp = tmp->next;
			pop--;
		}
	}
	return (0);
}
