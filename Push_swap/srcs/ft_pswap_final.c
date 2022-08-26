/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pswap_final.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zharzi <zharzi@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/11 08:04:40 by zharzi            #+#    #+#             */
/*   Updated: 2022/08/26 16:41:53 by zharzi           ###   ########.fr       */
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
