/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lock_elem.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zharzi <zharzi@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/17 09:27:43 by zharzi            #+#    #+#             */
/*   Updated: 2022/08/26 17:54:57 by zharzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pswap.h"

int	ft_lock_elem(t_list **astack, t_control **val)
{
	t_list	*tmp1;

	if ((*val)->pop_a && (*val)->lock)
	{
		tmp1 = *astack;
		while (tmp1->next && !ft_is_lock(tmp1->next, astack, *val))
			tmp1 = tmp1->next;
		if (ft_is_lock(tmp1->next, astack, *val))
		{
			if (ft_test_index(tmp1, tmp1->next) == -1)
			{
				(*val)->pop_a--;
				(*val)->lock++;
				(*val)->max--;
				return (1);
			}
		}
	}
	return (0);
}

/*
int	ft_lock_elem(t_list **astack, t_control	**values)
{
	t_list	*tmp;
	int		pop;

	pop = (*values)->pop_a;
	tmp = *astack;
	ft_printf("\n\tlock elem\n");
	while (pop > 1)
	{
		tmp = tmp->next;
		pop--;
	}
	if (tmp->index == (*values)->max)
	{
		(*values)->max -= 1;
		(*values)->pop_a -= 1;
		(*values)->lock += 1;
		return (1);
	}
	return (0);
}
*/
/*
int	ft_lock_elem(t_list **astack, t_list **bstack, t_control **val)
{
	t_list	*tmp1;
	t_list	*tmp2;
	int		test;

	tmp1 = *astack;
	test = 0;
	ft_printf("\tlock elem\n");
	if (!(*val)->lock && ++test)
		ft_homing_max(astack, bstack, *val);
	tmp2 = ft_lst_find_one(*astack, (*val)->pop_a);
	if ((*val)->pop_a > 0 && (*val)->lock \
	&& !ft_pswap_final(astack, bstack, *val))
	{
		if (tmp1 && tmp1->next && tmp1->next != tmp2)
			tmp1 = tmp1->next;
		if (tmp1->index == tmp1->next->index - 1 && ++test)
		{
			(*val)->lock += 1;
			(*val)->pop_a -= 1;
		}
	}
	if (tmp2->next && tmp2->index == tmp2->next->index - 1 && ++test)
	{
		(*val)->lock += 1;
		(*val)->pop_ea -= 1;
	}
	ft_printf("\tLOCK ELEM TEST = %d\n", test);
	ft_pswap_view(astack, bstack, *val);
	return (test);
}*/
