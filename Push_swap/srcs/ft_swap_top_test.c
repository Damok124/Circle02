/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap_top_test.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zharzi <zharzi@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/12 11:28:59 by zharzi            #+#    #+#             */
/*   Updated: 2022/08/26 12:13:13 by zharzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pswap.h"

void	ft_swap_top_test(t_list **astack, t_list **bstack, t_control *val)
{
	t_list	*ta1;
	t_list	*tb1;

	ta1 = NULL;
	tb1 = NULL;
	ft_printf("\tswap top test\n");
	ft_lock_elem(astack, bstack, &val);
	if (val->pop_a > 1)
	{
		if (*astack && (*astack)->next)
			ta1 = *astack;
		if (*bstack && (*bstack)->next)
			tb1 = *bstack;
		if (ta1->index == val->ac - 1)//nouveau
			ft_move_ra(astack, val);
		else if (ta1 && tb1 && ft_index_comp(ta1, ta1->next) \
		&& !ft_index_comp(tb1, tb1->next))
			ft_move_ss(astack, bstack, val);
		else if (ta1 && ta1->next && ft_index_comp(ta1, ta1->next))
			ft_move_sa(astack, val);
		else if (tb1 && tb1->next && !ft_index_comp(tb1, tb1->next))
			ft_move_sb(bstack, val);
		//ft_pswap_view(astack, bstack, val);
	}
}
//ajouter de quoi swap en fonction des plus grands ou petits, modif des tests
//index par index comp
/*
void	ft_swap_top_test(t_list **astack, t_list **bstack, t_control *val)
{
	t_list	*ta1;
	t_list	*tb1;

	ta1 = NULL;
	tb1 = NULL;
	ft_printf("\tswap top test\n");
	if (*astack && (*astack)->next)
		ta1 = *astack;
	if (*bstack && (*bstack)->next)
		tb1 = *bstack;
	if (ft_test_index(ta1, ta1->next) == 1 \
	&& ft_test_index(tb1, tb1->next) == -1)
		ft_move_ss(astack, bstack);
	else if (ta1 && ta1->next && ft_test_index(ta1, ta1->next) == 1)
		ft_move_sa(astack);
	else if (tb1 && tb1->next && ft_test_index(tb1, tb1->next) == -1)
		ft_move_sb(bstack);
	ft_pswap_view(astack, bstack, val);
}
*/
