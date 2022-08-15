/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_first_estack.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zharzi <zharzi@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 14:07:02 by zharzi            #+#    #+#             */
/*   Updated: 2022/08/15 14:08:49 by zharzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pswap.h"

t_list	*ft_first_estack(t_list **stack, int pop)
{
	t_list	*tmp;

	tmp = *stack;
	while (pop)
	{
		pop--;
		tmp = tmp->next;
	}
	return (tmp);
}
