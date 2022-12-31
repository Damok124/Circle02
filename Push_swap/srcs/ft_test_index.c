/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_test_index.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zharzi <zharzi@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/31 11:58:22 by zharzi            #+#    #+#             */
/*   Updated: 2022/12/31 12:31:39 by zharzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pswap.h"

int	ft_test_index(t_stack *elem1, t_stack *elem2)
{
	if (elem1 && elem2 && elem1->index == (elem2->index) - 1)
		return (ASCENDING);
	if (elem1 && elem2 && elem1->index == (elem2->index) + 1)
		return (DESCENDING);
	return (0);
}
