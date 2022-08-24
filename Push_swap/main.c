/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zharzi <zharzi@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 06:22:33 by zharzi            #+#    #+#             */
/*   Updated: 2022/08/24 21:07:03 by zharzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pswap.h"

void	ft_adv_distri_a(t_list **astack, t_list **bstack, t_control *val)
{
	while (ft_lstsize(*astack) > 4)
	{
		while (val->pop_a)
		{
			ft_pswap_distri(astack, bstack, val);
			ft_swap_top_test(astack, bstack, val);
		}
		ft_update_thirds(val, 0);
		val->pop_a += val->pop_ea;
		val->pop_ea = 0;
	}
}

void	ft_main_pattern(t_list **astack, t_list **bstack, t_control *val)
{
	while (val->pop_a > 3)
		ft_adv_distri_a(astack, bstack, val);
}

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
	ft_printf("MOVES SUM = %d\n", val.total);//probleme 1 3 2, le homing ne fonctionne pas
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
/*
void	ft_main_pattern(t_list **astack, t_list **bstack, t_control *val)
{
	while (!ft_pswap_final(astack, bstack, val) && val->pop_a)
	{
		ft_printf("\tmain_pattern\n");
		if (ft_lock_elem(astack, bstack, &val))
			if (ft_pswap_final(astack, bstack, val))
				return ;
		if (!ft_pswap_final(astack, bstack, val) && \
		ft_swap_test_b(astack, bstack, val))
		{
			if (ft_lock_elem(astack, bstack, &val))
				if (ft_pswap_final(astack, bstack, val))
					return ;
		}
//		if (val->pop_a == 3)
//			ft_pswap_small(astack, bstack, val);
		if (ft_pswap_final(astack, bstack, val))
			return ;
		ft_pswap_distri(astack, bstack, val);
		if (ft_pswap_final(astack, bstack, val))
			return ;
		if (ft_lock_elem(astack, bstack, &val))
			if (ft_pswap_final(astack, bstack, val))
				return ;
		ft_printf("\tfin de main_pattern\n");
	}
}

void	ft_push_swap(int ac, t_list **astack, t_list **bstack)
{
	t_control	val;

	if (ac == 1)
		return ;
	val = ft_fill_controlval(ac);
	ft_pswap_view(astack, bstack, &val);
	while (!ft_pswap_final(astack, bstack, &val))
	{
		ft_main_pattern(astack, bstack, &val);
		ft_reborn_astack(astack, bstack, &val);
	}
	ft_ending_bstack(astack, bstack, &val);
	ft_pswap_view(astack, bstack, &val);
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
