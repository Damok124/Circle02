/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zharzi <zharzi@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 06:22:33 by zharzi            #+#    #+#             */
/*   Updated: 2022/08/17 22:55:23 by zharzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pswap.h"
/*
void	ft_pswap_pattern(t_list **astack, t_list **bstack, t_control *val)
{
	while (!ft_pswap_final(astack, bstack, val) && val->pop_a)
	{
		ft_pswap_view(astack, bstack, val);
		while (ft_lock_elem(astack, &val))
			if (ft_pswap_final(astack, bstack, val))
				return ;
		while (!ft_pswap_final(astack, bstack, val) && \
		ft_swap_test(astack, bstack, val))
		{
			while (ft_lock_elem(astack, &val))
				if (ft_pswap_final(astack, bstack, val))
					return ;
		}
		if (ft_pswap_final(astack, bstack, val))
			return ;
		ft_pswap_distri(astack, bstack, val);
		if (ft_pswap_final(astack, bstack, val))
			return ;
		while (ft_lock_elem(astack, &val))
			if (ft_pswap_final(astack, bstack, val))
				return ;
	}
}
*/
void	ft_push_swap(int ac, t_list **astack, t_list **bstack)
{
	t_control	val;

	if (ac == 1)
		return ;
	val = ft_fill_controlval(ac);
	if (val.ac <= 5)/////////////////////////////////////
		ft_homing_max(astack, bstack, &val);/////////////
	while (!ft_pswap_final(astack, bstack, &val))
	{
		ft_pswap_pattern(astack, bstack, &val);
		ft_recall_eastack(astack, bstack, &val);
	}
	ft_ending_bstack(astack, bstack, &val);
	ft_pswap_view(astack, bstack, &val);
}
/*
strategie pour demain : test unitaire du fonctionnement des fonctions,
tentative de construction de pattern alternatif, au moins pour les plus petits
*/
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
