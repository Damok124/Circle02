/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zharzi <zharzi@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 06:22:33 by zharzi            #+#    #+#             */
/*   Updated: 2022/07/25 00:31:36 by zharzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pswap.h"

int	main(int ac, char *av[])
{
	t_list	**tab;
	void	(*del)(void *);

	del = &ft_ptr_to_null;
	ac -= 1;
	av += 1;
	ft_printf("test int du tab %d\n", ft_check_strs_int(av));
	//CHANGEMENT DE STRAT ON VA AU PLUS SIMPLE, liste d'int en dur
	//transformer args en liste chainée
	tab = ft_strs_to_tab(ac, av);
	ft_show_tab(tab, 1);
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
	ft_lstclear(tab, del);
	free(tab);
	return (0);
}
