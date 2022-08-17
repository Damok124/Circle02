/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pswap_final.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zharzi <zharzi@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/11 08:04:40 by zharzi            #+#    #+#             */
/*   Updated: 2022/08/16 20:47:24 by zharzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pswap.h"

int	ft_pswap_final(t_list **astack, t_list **bstack, t_control *val)
{
	t_list	*tmp1;
	t_list	*tmp2;

	tmp1 = *astack;
	tmp2 = *bstack;
	if ((!tmp2 || ft_stack_check_order(tmp2, val->pop_b + val->pop_eb, 1)) \
	&& ft_stack_check_order(tmp1, val->pop_a + val->lock + val->pop_ea, -1))
		return (1);
	return (0);
}

/*
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
*/
