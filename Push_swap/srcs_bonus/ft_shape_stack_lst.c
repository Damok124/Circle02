/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_shape_stack_lst.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zharzi <zharzi@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/31 11:58:22 by zharzi            #+#    #+#             */
/*   Updated: 2022/12/31 15:31:48 by zharzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pswap_bonus.h"

t_stack	*ft_shape_stack_lst(int size)
{
	t_stack	*elem;

	elem = NULL;
	if (size)
	{
		elem = (t_stack *)malloc(sizeof(t_stack));
		if (!elem)
			return (NULL);
		elem->next = ft_shape_stack_lst(size - 1);
	}
	return (elem);
}
