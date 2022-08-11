/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pswap_final_test.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zharzi <zharzi@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/11 08:04:40 by zharzi            #+#    #+#             */
/*   Updated: 2022/08/11 08:04:55 by zharzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pswap.h"

int	ft_pswap_final_test(t_list **astack, t_list **bstack)
{
	t_list	*tmp;
	int		test;

	test = 1;
	tmp = *bstack;
	if (tmp)
		return (0);
	tmp = *astack;
	while (tmp)
	{
		if (tmp->index != test)
			return (0);
		test++;
		tmp = tmp->next;
	}
	return (1);
}
