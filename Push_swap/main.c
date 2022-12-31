/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zharzi <zharzi@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 06:22:33 by zharzi            #+#    #+#             */
/*   Updated: 2022/12/31 12:53:14 by zharzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pswap.h"

void	ft_push_swap(int *tab, int size)
{
	t_stack	**top_a;
	t_stack	**top_b;
	t_stack	*a;
	t_stack	*b;

	a = ft_shape_stack_lst(size);
	b = NULL;
	ft_init_stack_a(&a, tab, size);
	top_a = &a;
	top_b = &b;
	if (size > 1 && !ft_check_stack_order(a, ASCENDING))
	{
		if (size == 2)
			ft_move_sa(top_a, PRINT_OK);
		else if (size == 3)
			ft_sort_trio(top_a);
		else if (size == 4)
			ft_sort_quartet(top_a, top_b);
		else if (size == 5)
			ft_sort_quintet(top_a, top_b);
		else
			ft_sort(top_a, top_b, (int [9]){19, 22, 28, 37, 50, 60, 79, 100});
	}
	ft_free_stack(top_a);
	ft_free_stack(top_b);
}

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
			ft_push_swap(tab, ac - 1);
			ft_true_free((void **)&tab);
		}
		else
			write(2, "Error\n", 6);
	}
	else
		write(2, "Error\n", 6);
	return (0);
}
