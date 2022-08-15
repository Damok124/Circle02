/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zharzi <zharzi@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 06:22:33 by zharzi            #+#    #+#             */
/*   Updated: 2022/08/15 20:46:28 by zharzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pswap.h"

void	ft_pswap_view(t_list **astack, t_list **bstack, t_control *val)
{
	ft_show_values(*val);
	ft_show_stacks(astack, bstack, val);
	ft_printf("-------------------------\n");
}

void	ft_push_swap(int ac, t_list **astack, t_list **bstack)
{
	t_control	values;

	if (ac == 1)
		return ;
	values = ft_fill_controlval(ac);
	while (values.pop_a)
	{
		ft_pswap_view(astack, bstack, &values);
		ft_pswap_distri(astack, bstack, &values);
		while (ft_swap_test(astack, bstack, &values))
			;
	}
	ft_pswap_view(astack, bstack, &values);

	//rediger les consequences d'une sequence dans l'ordre
	//verif et modif des regles de swap
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
