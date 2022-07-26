/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zharzi <zharzi@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 06:22:33 by zharzi            #+#    #+#             */
/*   Updated: 2022/07/26 19:37:21 by zharzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pswap.h"

int	main(int ac, char *av[])
{
	t_elem	*list;
	//int		i;

	//i = -1;
	ac -= 1;
	av += 1;
	if (!ft_check_strs_int(av))
		return (0);
	list = ft_strs_to_intlst(ac, av);
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
	//while (++i < ac)
	//	free(list[i]);
	free(list);
	return (0);
}
