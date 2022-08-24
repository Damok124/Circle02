/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_index_comp.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zharzi <zharzi@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/21 15:06:31 by zharzi            #+#    #+#             */
/*   Updated: 2022/08/21 17:45:51 by zharzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pswap.h"

int	ft_index_comp(t_list *elem1, t_list *elem2)
{
	if (elem1 && elem2 && elem1->index > elem2->index)
		return (1);
	return (0);
}
