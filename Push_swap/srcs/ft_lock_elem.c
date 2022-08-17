/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lock_elem.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zharzi <zharzi@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/17 09:27:43 by zharzi            #+#    #+#             */
/*   Updated: 2022/08/17 16:42:43 by zharzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pswap.h"

int	ft_lock_elem(t_list **astack, t_control	**values)
{
	t_list	*tmp;
	int		pop;

	pop = (*values)->pop_a;
	tmp = *astack;
	ft_printf("\n\tlock elem\n");
	while (pop > 1)
	{
		tmp = tmp->next;
		pop--;
	}
	if (tmp->index == (*values)->max)
	{
		(*values)->max -= 1;
		(*values)->pop_a -= 1;
		(*values)->lock += 1;
		return (1);
	}
	return (0);
}
