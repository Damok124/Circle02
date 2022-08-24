/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_test_index.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zharzi <zharzi@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/13 10:25:06 by zharzi            #+#    #+#             */
/*   Updated: 2022/08/21 14:16:46 by zharzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pswap.h"

int	ft_test_index(t_list *tmp1, t_list *tmp2)
{
	//if (tmp1 && tmp2 && tmp1->index < (tmp2->index))
	//	return (-2);
	if (tmp1 && tmp2 && tmp1->index == (tmp2->index) - 1)
		return (-1);
	//if (tmp1 && tmp2 && tmp1->index > (tmp2->index))
	//	return (2);
	if (tmp1 && tmp2 && tmp1->index == (tmp2->index) + 1)
		return (1);
	return (0);
}
//essentiel pour pswap final
