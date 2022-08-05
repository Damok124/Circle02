/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zharzi <zharzi@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 06:22:33 by zharzi            #+#    #+#             */
/*   Updated: 2022/08/05 00:45:02 by zharzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pswap.h"

void	ft_push_swap(int ac, t_list **list)
{
	if (list)
	{
		ft_show_lstint(list, 1);
		(void)ac;
		ft_full_free_lst(list);
	}
}

int	main(int ac, char *av[])
{
	int	*trueav;
	int	oldac;

	oldac = ac;
	trueav = ft_pswap_parsing(&ac, av + 1);
	if (!trueav)
	{
		write(2, "Error\n", 6);
		return (1);
	}
	ft_sort_int_tab(trueav, ac);
	if (!ft_check_dup_int(ac, trueav))
	{
		ft_true_free(trueav);
		write(2, "Error\n", 6);
		return (1);
	}
	ft_true_free(trueav);
	ac = oldac;
	trueav = ft_pswap_parsing(&ac, av + 1);
	ft_push_swap(ac, ft_tab_to_lst(ac, trueav));
	ft_true_free(trueav);
	return (0);
}
