/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zharzi <zharzi@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 06:22:33 by zharzi            #+#    #+#             */
/*   Updated: 2022/07/24 18:20:54 by zharzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pswap.h"

int	main(int ac, char *av[])
{
	int	i;
	int	**tab;

	i = 0;
	ac -= 1;
	av += 1;
	(void)ac;
	ft_printf("test int du tab %d\n", ft_check_strs_int(av));
	tab = ft_strs_to_tab(av);
	ft_printf("test int du tab %d\n", ft_check_strs_int(av));
	ft_printf("pour i = %d, tab[i] = %d\n", i, *tab);
	//tester le tableau d'arg,
	//le transformer en tab int
	//test la ft doublon
	ft_move_sa(&av[1], &av[0]);
	ft_move_sb(&av[1], &av[0]);
	ft_move_ss(&av[1], &av[0]);
	ft_move_pa(&av[1], &av[0]);
	ft_move_pb(&av[1], &av[0]);
	ft_move_ra(&av[1], &av[0]);
	ft_move_rb(&av[1], &av[0]);
	ft_move_rr(&av[1], &av[0]);
	ft_move_rra(&av[1], &av[0]);
	ft_move_rrb(&av[1], &av[0]);
	ft_move_rrr(&av[1], &av[0]);
	if (tab)
		ft_true_free(tab);
	return (0);
}
