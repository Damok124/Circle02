/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zharzi <zharzi@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 06:22:33 by zharzi            #+#    #+#             */
/*   Updated: 2022/07/24 05:07:15 by zharzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pswap.h"

int	main(int ac, char *av[])
{
	(void)ac;
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
	return (0);
}
