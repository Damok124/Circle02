/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checker.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zharzi <zharzi@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/31 21:00:52 by zharzi            #+#    #+#             */
/*   Updated: 2022/12/31 21:07:05 by zharzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pswap_bonus.h"

void	ft_print_result(t_stack **top_a, t_stack **top_b)
{
	t_stack	*tmp;
	int		check;

	tmp = *top_a;
	check = 1;
	if (*top_b || !*top_a)
		check = 0;
	else
	{
		while (tmp && tmp->next)
		{
			if (tmp->index > tmp->next->index)
				check = 0;
			tmp = tmp->next;
		}
	}
	if (check)
		ft_printf("OK\n");
	else
		ft_printf("KO\n");
}

void	ft_apply_move(t_stack **top_a, t_stack **top_b, int action)
{
	if (action == 0)
		ft_move_rra(top_a, PRINT_OK);
	if (action == 1)
		ft_move_rrb(top_b, PRINT_OK);
	if (action == 2)
		ft_move_rrr(top_a, top_b, PRINT_OK);
	if (action == 3)
		ft_move_pa(top_a, top_b, PRINT_OK);
	if (action == 4)
		ft_move_pb(top_a, top_b, PRINT_OK);
	if (action == 5)
		ft_move_ra(top_a, PRINT_OK);
	if (action == 6)
		ft_move_rb(top_b, PRINT_OK);
	if (action == 7)
		ft_move_rr(top_a, top_b, PRINT_OK);
	if (action == 8)
		ft_move_sa(top_a, PRINT_OK);
	if (action == 9)
		ft_move_sb(top_b, PRINT_OK);
	if (action == 10)
		ft_move_ss(top_a, top_b, PRINT_OK);
}

int	ft_valid_buffer(char **names, char *buffer)
{
	int	i;

	i = 0;
	if (ft_strlen(buffer) == 1 && buffer[0] == '\n')
		return (-1);
	while (names[i] && ft_strncmp(names[i], buffer, ft_strlen(buffer) + 1))
		i++;
	if (i <= 10)
		return (i);
	return (-2);
}

void	ft_checker(t_stack **top_a, t_stack **top_b)
{
	char	**names;
	char	*buffer;
	int		action;

	names = \
	ft_split("rra\n rrb\n rrr\n pa\n pb\n ra\n rb\n rr\n sa\n sb\n ss\n", ' ');
	buffer = get_next_line(STDIN_FILENO);
	while (buffer && names && ft_valid_buffer(names, buffer) != -1)
	{
		action = ft_valid_buffer(names, buffer);
		if (action >= 0)
			ft_apply_move(top_a, top_b, action);
		else if (action == -2)
			ft_printf("Invalid instruction. Retry.\n");
		ft_true_free((void **)&buffer);
		buffer = get_next_line(STDIN_FILENO);
	}
	if (ft_valid_buffer(names, buffer) == -1)
		get_next_line(1025);
	if (buffer)
		ft_true_free((void **)&buffer);
	ft_print_result(top_a, top_b);
	ft_full_free((void **)names);
}

void	ft_stacks_to_checker(int *tab, int size)
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
	ft_checker(top_a, top_b);
	ft_free_stack(top_a);
	ft_free_stack(top_b);
}
