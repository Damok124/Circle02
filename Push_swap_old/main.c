/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zharzi <zharzi@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 06:22:33 by zharzi            #+#    #+#             */
/*   Updated: 2022/08/30 14:56:43 by zharzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pswap.h"

void	ft_main_pattern(t_list **astack, t_list **bstack, t_control *val)
{
	int	i;
	int	rank;

	i = 0;
	rank = 0;
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
	}
}

void	ft_push_swap(int ac, t_list **astack, t_list **bstack)
{
	t_control	val;

	if (ac == 1)
		return ;
	val = ft_fill_controlval(ac);
	if (val.ac <= 5 && !ft_pswap_final(astack, bstack, &val))
		ft_small(astack, bstack, &val);
	else if (!ft_pswap_final(astack, bstack, &val))
		ft_main_pattern(astack, bstack, &val);
	ft_ending_bstack(astack, bstack, &val);
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
	ft_push_swap(ac, &listav, &bstack);
	return (ft_true_free(tabav), ft_true_free(sortedav), \
		ft_full_free_lst(&listav), 0);
}
