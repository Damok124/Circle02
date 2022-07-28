/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zharzi <zharzi@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 06:22:33 by zharzi            #+#    #+#             */
/*   Updated: 2022/07/29 01:16:01 by zharzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pswap.h"

int	main(int ac, char *av[])
{
	int	*tab;
	int	i;

	(void)ac;
	i = -1;
	av += 1;
	tab = ft_parsing_to_int(av);
	while (tab[++i])
		ft_putnbr_fd(tab[i], 1);
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
	ft_true_free(tab);
	return (0);
}

/*
test({"52"}, true);sequence monoarg
test({"1 2 3"}, true);
test({"1 2 3 4 5"}, true);
test({"5 4 3 2 1"}, true);
test({"52 14 15"}, true);
test({"5 2 3 4 8"}, true);
test({"42 -500 -2845 -21 54784 1541"}, true);
test({"2147483647 -2147483648"}, true); limits.h

test({"5", "4", "3"}, true);sequence multiarg
test({"5", "3", "2", "1"}, true);
test({"5", "1", "0", "2"}, true);

test({"1 2 3 "}, true); sequence monoarg + espace
test({" 1 2 3"}, true);
test({" 1 2 3 "}, true);
test({" 1   2               3 "}, true);

test({"-0"}, true); sequence monoarg + zero
test({"05 02"}, true);
test({"052 02"}, true);
test({"05 08 0009 00010 2"}, true);
test({"0002147483647 -002147483648"}, true); limits.h

test({" 5", "8"}, true); sequence multiarg + espace
test({" 5", "3  ", " 2", " 1"}, true);
test({"42", "500", "-2845", "-21", " 54784", "1541"}, true);

test({"4 2 3", "5"}, true); sequence mixte

test({"1 e 2 3 4 5"}, false); intrus
test({"5 4A 3"}, false); intrus
test({"05 5 005"}, false);doublon
test({"-00", "00"}, false);doublon
test({"-0", "0"}, false);doublon
test({"0", "-0"}, false);doublon
*/

//je dois
//
//traiter mes args
//tester les int
//tester les doublons
//produire une liste chainée
//verifier la liste chainée
//
//
//
//
