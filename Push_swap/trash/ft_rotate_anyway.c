/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rotate_anyway.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zharzi <zharzi@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/19 17:52:27 by zharzi            #+#    #+#             */
/*   Updated: 2022/08/20 23:06:04 by zharzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pswap.h"

void	ft_rotate_anyway(t_list **astack, t_list **bstack, t_control *val)
{
	t_list	*ta1;
	t_list	*ta2;

	ft_printf("\trotate anyway\n");
	ta1 = *astack;
	if (!ta1 || ft_is_lock(ta1, astack, val))
		return ;
	if (ta1 && (val->pop_a + val->lock + val->pop_ea) > 1)
		ta2 = ft_lstlast(*astack);
	if (!ta2 || ft_is_lock(ta2, astack, val))
		return ;
	if (ta1->index >= ft_find_lstavg(astack))
		ft_push_to_ea(astack, bstack, val);
	else if (val->pop_ea)
		ft_get_from_ea(astack, bstack, val);
	else if (val->pop_a)
		ft_swap_top_test(astack, bstack, val);
	ft_pswap_view(astack, bstack, val);
}
//pas parfaite
