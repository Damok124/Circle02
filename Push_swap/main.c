/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zharzi <zharzi@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 06:22:33 by zharzi            #+#    #+#             */
/*   Updated: 2022/08/14 17:20:11 by zharzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pswap.h"

void	ft_pswap_distri(t_list **astack, t_list **bstack, t_control *val)
{
	while (val->pop_a)
	{
		if ((*astack)->index > val->lastthird)
			ft_push_to_ea(astack, val);
		else if ((*astack)->index < val->firstthird)
			ft_push_to_eb(astack, bstack, val);
		else
			ft_push_to_b(astack, bstack, val);
		ft_swap_test(astack, bstack, val);
		//ecrire fonction de verif
		ft_show_values(*val);
		ft_show_stacks(astack, bstack);
		ft_printf("-------------------------\n");
	}
}

void	ft_push_swap(int ac, t_list **astack, t_list **bstack)
{
	t_control	values;

	if (ac == 1)
		return ;
	values = ft_fill_controlval(ac);//problem index
	ft_show_values(values);
	ft_show_stacks(astack, bstack);
	ft_pswap_distri(astack, bstack, &values);

	ft_ending_bstack(astack, bstack, &values);
	ft_show_values(values);
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
