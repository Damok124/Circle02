/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zharzi <zharzi@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 06:22:33 by zharzi            #+#    #+#             */
/*   Updated: 2022/08/26 15:51:52 by zharzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pswap.h"

void	ft_main_pattern(t_list **astack, t_list **bstack, t_control *val)
{
	int	i;
	int	rank;

	i = 0;
	rank = 0;
	ft_printf("\tmain pattern\n");
	while (!ft_pswap_final(astack, bstack, val))
	{
		while (i < val->ac && !ft_pswap_final(astack, bstack, val))
		{
			if (((*astack)->index >> rank) & 0x1)
				ft_move_ra(astack, val);
			else
				ft_move_pb(astack, bstack, val);
			i++;
		}
		i = 0;
		while (*bstack)
			ft_move_pa(astack, bstack, val);
		rank++;
		ft_pswap_view(astack, bstack, val);
	}
	ft_homing_max(astack, bstack, val);
	while (ft_lock_elem(astack, bstack, &val))
		;
}

void	ft_push_swap(int ac, t_list **astack, t_list **bstack, char **av)
{
	t_control	val;

	if (ac == 1)
		return ;
	val = ft_fill_controlval(ac, av);
	ft_pswap_view(astack, bstack, &val);
	if (val.ac <= 5 && !ft_pswap_final(astack, bstack, &val))
		ft_small(astack, bstack, &val);
	else if (!ft_pswap_final(astack, bstack, &val))
		ft_main_pattern(astack, bstack, &val);
	ft_ending_bstack(astack, bstack, &val);
	ft_pswap_view(astack, bstack, &val);
	ft_printf("MOVES SUM = %d\n", val.total);//probleme avec 5 1 4 2 3
}

int	main(int ac, char *av[])
{
	int		*tabav;
	int		*sortedav;
	t_list	*listav;
	t_list	*bstack;

	if (ac == 1)
		return (0);
	bstack = NULL;
	tabav = ft_pswap_parsing(&ac, av + 1);
	sortedav = ft_sort_int_tab(tabav, ac);
	if (!tabav || !ft_check_dup_int(ac, sortedav))
	{
		if (!ft_check_dup_int(ac, sortedav))
		{
			ft_true_free(sortedav);
			ft_true_free(tabav);
		}
		write(2, "Error\n", 6);
		return (1);
	}
	listav = ft_tab_to_lst(ac, tabav);
	ft_index_intlist(&listav, sortedav, ac);
	ft_push_swap(ac, &listav, &bstack, av);
	ft_true_free(tabav);
	ft_true_free(sortedav);
	ft_full_free_lst(&listav);
	return (0);
}
/*
void	ft_push_swap(int ac, t_list **astack, t_list **bstack)
{
	t_control	val;

	if (ac == 1)
		return ;
	val = ft_fill_controlval(ac);
	ft_pswap_view(astack, bstack, &val);
	if (val.ac <= 5 && !ft_pswap_final(astack, bstack, &val))
		ft_small(astack, bstack, &val);
	else if (!ft_pswap_final(astack, bstack, &val))
		ft_main_pattern(astack, bstack, &val);
	ft_ending_bstack(astack, bstack, &val);
	ft_pswap_view(astack, bstack, &val);
	ft_printf("MOVES SUM = %d\n", val.total);
}

int	main(int ac, char *av[])
{
	int		*tabav;
	int		*sortedav;
	t_list	*listav;
	t_list	*bstack;

	bstack = NULL;
	tabav = ft_pswap_parsing(&ac, av + 1);
	sortedav = ft_sort_int_tab(tabav, ac);
	if (!tabav || !ft_check_dup_int(ac, sortedav))
	{
		if (!ft_check_dup_int(ac, sortedav))
		{
			ft_true_free(sortedav);
			ft_true_free(tabav);
		}
		write(2, "Error\n", 6);
		return (1);
	}
	listav = ft_tab_to_lst(ac, tabav);
	ft_index_intlist(&listav, sortedav, ac);
	ft_push_swap(ac, &listav, &bstack);
	ft_true_free(tabav);
	ft_true_free(sortedav);
	ft_full_free_lst(&listav);
	return (0);
}
*/
/*
void	ft_adv_distri_a(t_list **astack, t_list **bstack, t_control *val)
{
	while (ft_lstsize(*astack) > 5)
	{
		while (val->pop_a)
		{
			ft_pswap_distri(astack, bstack, val);
			ft_swap_top_test(astack, bstack, val);
		}
		if (val->lastthird < val->ac * 0.95)
			ft_update_thirds(val, 2);
		val->pop_a += val->pop_ea;
		val->pop_ea = 0;
	}
}

int	ft_check_limit(t_list **stack, int limit, char direction)
{
	t_list	*tmp;

	tmp = *stack;
	if (direction == 'u')
	{
		while (tmp)
		{
			if (tmp->index > limit)
				return (0);
			tmp = tmp->next;
		}
	}
	if (direction == 'd')
	{
		while (tmp)
		{
			if (tmp->index < limit)
				return (0);
			tmp = tmp->next;
		}
	}
	return (1);
}

void	ft_refill_a(t_list **astack, t_list **bstack, t_control *val)
{
	while (*bstack && ft_check_limit(astack, (val->max - 2), 'd') \
	&& !ft_pswap_final(astack, bstack, val))
	{
		ft_printf("\trefill a\n");
		ft_swap_top_test(astack, bstack, val);
		if (ft_lstsize(*bstack) >= 2 \
		&& ft_index_comp(ft_lstlast(*bstack), *bstack))
			ft_move_rrb(bstack, val);
		ft_swap_top_test(astack, bstack, val);//new
		ft_move_pa(astack, bstack, val);
		ft_swap_top_test(astack, bstack, val);
		while (ft_lock_elem(astack, bstack, &val))
			;
	}
	ft_pswap_view(astack, bstack, val);
}

void	ft_pswap_distri_b(t_list **astack, t_list **bstack, t_control *val)
{
	t_list	*tmp;

	tmp = NULL;
	if (*bstack)
		tmp = ft_lstlast(*bstack);
	ft_printf("\tpswap distri b\n");
	if (ft_lstsize(*bstack) > 1 && ft_index_comp(tmp, *bstack))
	{
		ft_move_rrb(bstack, val);
		ft_move_pa(astack, bstack, val);
	}
	else if ((*bstack)->index >= val->lastthird || (*bstack)->index <= val->firstthird)
	{
		ft_move_pa(astack, bstack, val);
		if ((*astack)->index <= val->firstthird \
		&& ft_test_index(*astack, ft_lst_find_one(*astack, 2)) != -1)
			ft_move_ra(astack, val);
	}
	else
		ft_move_rb(bstack, val);
	ft_pswap_view(astack, bstack, val);
}

void	ft_main_pattern(t_list **astack, t_list **bstack, t_control *val)
{
	ft_adv_distri_a(astack, bstack, val);
	if (!val->lock && !ft_pswap_final(astack, bstack, val))
		ft_homing_max(astack, bstack, val);
	while (ft_lock_elem(astack, bstack, &val))
		;
	ft_refill_a(astack, bstack, val);
	ft_update_thirds(val, 1);
	ft_update_thirds(val, 2);
	while (!ft_check_limit(bstack, (val->firstthird), 'u'))//nouveau
	{
		ft_pswap_distri_b(astack, bstack, val);
		ft_swap_top_test(astack, bstack, val);
	}
	ft_pswap_view(astack, bstack, val);
}
*/
