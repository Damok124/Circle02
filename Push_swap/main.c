/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zharzi <zharzi@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 06:22:33 by zharzi            #+#    #+#             */
/*   Updated: 2022/08/04 03:59:17 by zharzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pswap.h"

int	main(int ac, char *av[])
{
	int	*trueav;

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
	ac++;
	trueav = ft_pswap_parsing(&ac, av + 1);
	//ft_tab_to_lst(trueav);
	ft_true_free(trueav);
	return (0);
}
