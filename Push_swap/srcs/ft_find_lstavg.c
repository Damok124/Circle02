/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_lstavg.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zharzi <zharzi@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/19 17:49:24 by zharzi            #+#    #+#             */
/*   Updated: 2022/08/19 17:49:27 by zharzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pswap.h"

int	ft_find_lstavg(t_list **stack)
{
	t_list	*tmp;
	int		result;
	int		rank;

	tmp = *stack;
	rank = 0;
	result = 0;
	while (tmp && ++rank)
	{
		result += tmp->index;
		tmp = tmp->next;
	}
	if (rank)
		result = result / rank;
	return (result);
}
