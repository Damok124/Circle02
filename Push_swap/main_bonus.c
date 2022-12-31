/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zharzi <zharzi@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 00:17:59 by zharzi            #+#    #+#             */
/*   Updated: 2022/12/31 21:06:30 by zharzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pswap_bonus.h"

int	main(int ac, char **argv)
{
	int	*tab;

	tab = NULL;
	if (ac == 1)
		return (0);
	if (ft_pswap_args_check(argv + 1))
	{
		tab = ft_get_parsed_tab(argv + 1);
		if (tab)
		{
			ft_stacks_to_checker(tab, ac - 1);
			ft_true_free((void **)&tab);
		}
		else
			write(2, "Error\n", 6);
	}
	else
		write(2, "Error\n", 6);
	return (0);
}
