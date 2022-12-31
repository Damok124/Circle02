/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zharzi <zharzi@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 06:22:33 by zharzi            #+#    #+#             */
/*   Updated: 2022/12/31 00:04:11 by zharzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pswap.h"

#define ASCENDING -1
#define DESCENDING 1
#define PRINT_OK 1
#define PRINT_KO 0

typedef struct s_stack {
	int				size;
	int				value;
	int				index;
	struct s_stack	*next;
}	t_stack;

void	ft_show_stack(t_stack **lst)
{
	t_stack	*tmp;

	tmp = *lst;
	while (tmp)
	{
		ft_printf("[%d]", tmp->index);
		tmp = tmp->next;
	}
	ft_printf("\n");
}

void	ft_show_it_all(t_stack **top_a, t_stack **top_b)
{
	ft_show_stack(top_b);
	ft_printf("\n");
	ft_show_stack(top_a);
	ft_printf("-------------------------------------------------------------");
	ft_printf("\n");
}

#include "pswap.h"

void	ft_move_pa(t_stack **astack, t_stack **bstack, int print)
{
	t_stack	*tmp1;

	if (*bstack)
	{
		tmp1 = *bstack;
		*bstack = (*bstack)->next;
		tmp1->next = *astack;
		*astack = tmp1;
		if (print)
			ft_printf("pa\n");
	}
}

#include "pswap.h"

void	ft_move_pb(t_stack **astack, t_stack **bstack, int print)
{
	t_stack	*tmp1;

	if (*astack)
	{
		tmp1 = *astack;
		*astack = (*astack)->next;
		tmp1->next = *bstack;
		*bstack = tmp1;
		if (print)
			ft_printf("pb\n");
	}
}

#include "pswap.h"

void	ft_move_ra(t_stack **astack, int print)
{
	t_stack	*tmp1;
	t_stack	*tmp2;

	if (*astack && (*astack)->next)
	{
		tmp2 = *astack;
		*astack = (*astack)->next;
		tmp2->next = NULL;
		tmp1 = *astack;
		while (tmp1 && tmp1->next)
			tmp1 = tmp1->next;
		tmp1->next = tmp2;
		if (print)
			ft_printf("ra\n");
	}
}

#include "pswap.h"

void	ft_move_rb(t_stack **bstack, int print)
{
	t_stack	*tmp1;
	t_stack	*tmp2;

	if (*bstack && (*bstack)->next)
	{
		tmp2 = *bstack;
		*bstack = (*bstack)->next;
		tmp2->next = NULL;
		tmp1 = *bstack;
		while (tmp1 && tmp1->next)
			tmp1 = tmp1->next;
		tmp1->next = tmp2;
		if (print)
			ft_printf("rb\n");
	}
}

#include "pswap.h"

void	ft_move_rra(t_stack **astack, int print)
{
	t_stack	*tmp1;
	t_stack	*tmp2;

	if (*astack && (*astack)->next)
	{
		tmp2 = *astack;
		while (tmp2 && tmp2->next)
		{
			tmp1 = tmp2;
			tmp2 = tmp2->next;
		}
		tmp1->next = NULL;
		tmp2->next = *astack;
		*astack = tmp2;
		if (print)
			ft_printf("rra\n");
	}
}

#include "pswap.h"

void	ft_move_rrb(t_stack **bstack, int print)
{
	t_stack	*tmp1;
	t_stack	*tmp2;

	if (*bstack && (*bstack)->next)
	{
		tmp2 = *bstack;
		while (tmp2 && tmp2->next)
		{
			tmp1 = tmp2;
			tmp2 = tmp2->next;
		}
		tmp1->next = NULL;
		tmp2->next = *bstack;
		*bstack = tmp2;
		if (print)
			ft_printf("rrb\n");
	}
}

#include "pswap.h"

void	ft_move_rr(t_stack **astack, t_stack **bstack, int print)
{
	t_stack	*tmp1;
	t_stack	*tmp2;

	if (*astack && (*astack)->next && *bstack && (*bstack)->next)
	{
		ft_move_ra(astack, PRINT_KO);
		ft_move_rb(bstack, PRINT_KO);
		if (print)
			ft_printf("rr\n");
	}
}

#include "pswap.h"

void	ft_move_rrr(t_stack **astack, t_stack **bstack, int print)
{
	if (*astack && (*astack)->next && *bstack && (*bstack)->next)
	{
		ft_move_rra(astack, PRINT_KO);
		ft_move_rrb(bstack, PRINT_KO);
		if (print)
			ft_printf("rrr\n");
	}
}

#include "pswap.h"

void	ft_move_sa(t_stack **astack, int print)
{
	t_stack	*elem3;
	t_stack	*elem2;

	if (*astack && (*astack)->next)
	{
		elem3 = (*astack)->next;
		elem2 = elem3;
		elem3 = elem3->next;
		elem2->next = *astack;
		(*astack)->next = elem3;
		*astack = elem2;
		if (print)
			ft_printf("sa\n");
	}
}

#include "pswap.h"

void	ft_move_sb(t_stack **bstack, int print)
{
	t_stack	*elem3;
	t_stack	*elem2;

	if (*bstack && (*bstack)->next)
	{
		elem3 = (*bstack)->next;
		elem2 = elem3;
		elem3 = elem3->next;
		elem2->next = *bstack;
		(*bstack)->next = elem3;
		*bstack = elem2;
		if (print)
			ft_printf("sb\n");
	}
}

#include "pswap.h"

void	ft_move_ss(t_stack **astack, t_stack **bstack, int print)
{
	t_stack	*elem3;
	t_stack	*elem2;

	if (*astack && (*astack)->next && *bstack && (*bstack)->next)
	{
		ft_move_sa(astack, PRINT_KO);
		ft_move_sb(bstack, PRINT_KO);
		if (print)
			ft_printf("ss\n");
	}
}

#include "pswap.h"

int	ft_stack_len(t_stack **stack)
{
	t_stack	*tmp;
	int		i;

	i = 0;
	tmp = *stack;
	while (tmp)
	{
		i++;
		tmp = tmp->next;
	}
	return (i);
}

#include "pswap.h"

int	ft_test_index(t_stack *elem1, t_stack *elem2)
{
	if (elem1 && elem2 && elem1->index == (elem2->index) - 1)
		return (ASCENDING);
	if (elem1 && elem2 && elem1->index == (elem2->index) + 1)
		return (DESCENDING);
	return (0);
}

#include "pswap.h"

int	ft_check_stack_order(t_stack *stack, int order)
{
	if (!stack)
		return (order);
	while (stack)
	{
		if (stack->next && ft_test_index(stack, stack->next) != order)
			return (0);
		stack = stack->next;
	}
	return (order);
}

#include "pswap.h"

int	ft_get_index(int value, int *ordered)
{
	int	i;

	i = 0;
	while (ordered)
	{
		if (ordered[i] == value)
			return (i);
		i++;
	}
	return (-1);
}

#include "pswap.h"

void	ft_init_stack_a(t_stack **a, int *tab, int size)
{
	t_stack	*tmp;
	int		*ordered;
	int		i;

	ordered = ft_sort_int_tab(tab, size);
	tmp = *a;
	i = 0;
	while (tmp && tab)
	{
		tmp->size = size;
		tmp->value = tab[i];
		tmp->index = ft_get_index(tab[i], ordered);
		tmp = tmp->next;
		i++;
	}
	ft_true_free((void **)&ordered);
}

#include "pswap.h"

t_stack	*ft_shape_stack_lst(int size)
{
	t_stack	*elem;

	elem = NULL;
	if (size)
	{
		elem = (t_stack *)malloc(sizeof(t_stack));
		if (!elem)
			return (NULL);
		elem->next = ft_shape_stack_lst(size - 1);
	}
	return (elem);
}

#include "pswap.h"

void	ft_free_stack(t_stack **stack)
{
	t_stack	*tmp1;
	t_stack	*tmp2;

	tmp1 = *stack;
	tmp2 = NULL;
	while (tmp1)
	{
		tmp2 = tmp1;
		tmp1 = tmp1->next;
		if (tmp2)
			ft_true_free((void **)&tmp2);
	}
}

#include "pswap.h"

t_stack *ft_get_last_elem(t_stack *lst)
{
	t_stack	*tmp;

	tmp = NULL;
	while (lst)
	{
		tmp = lst;
		lst = lst->next;
	}
	return (tmp);
}

#include "pswap.h"

void	ft_drain_b(t_stack **astack, t_stack **bstack)
{
	while (*bstack)
		ft_move_pa(astack, bstack, PRINT_OK);
}

#include "pswap.h"

void	ft_sort_trio(t_stack **top_a)
{
	t_stack	*tmp;

	if ((*top_a)->index == (*top_a)->size - 1)
		ft_move_ra(top_a, PRINT_OK);
	tmp = ft_get_last_elem(*top_a);
	if (!ft_check_stack_order(*top_a, ASCENDING) && tmp->index != tmp->size - 1)
		ft_move_rra(top_a, PRINT_OK);
	tmp = ft_get_last_elem(*top_a);
	if (!ft_check_stack_order(*top_a, ASCENDING) && tmp->index == tmp->size - 1)
		ft_move_sa(top_a, PRINT_OK);
}

#include "pswap.h"

void	ft_sort_quartet(t_stack **top_a, t_stack **top_b)
{
	t_stack	*tmp;

	tmp = ft_get_last_elem(*top_a);
	if (!ft_check_stack_order(*top_a, ASCENDING) && tmp->index == 0)
		ft_move_rra(top_a, PRINT_OK);
	while (!ft_check_stack_order(*top_a, ASCENDING) && (*top_a)->index != 0)
	{
		ft_move_ra(top_a, PRINT_OK);
		tmp = ft_get_last_elem(*top_a);
	}
	if (!ft_check_stack_order(*top_a, ASCENDING) && (*top_a)->index == 0)
	{
		ft_move_pb(top_a, top_b, PRINT_OK);
		ft_sort_trio(top_a);
	}
}

#include "pswap.h"

void	ft_sort_quintet(t_stack **top_a, t_stack **top_b)
{
	t_stack	*tmp;
	int		n;

	n = 0;
	tmp = ft_get_last_elem(*top_a);
	while (n != 2 && !ft_check_stack_order(*top_a, ASCENDING))
	{
		if (tmp->index == 0 || tmp->index == 1)
			ft_move_rra(top_a, PRINT_OK);
		if ((*top_a)->index == 0 || (*top_a)->index == 1)
		{
			ft_move_pb(top_a, top_b, PRINT_OK);
			n++;
		}
		else
			ft_move_ra(top_a, PRINT_OK);
		tmp = ft_get_last_elem(*top_a);
	}
	if (!ft_check_stack_order(*top_b, DESCENDING))
		ft_move_sb(top_b, PRINT_OK);
	ft_sort_trio(top_a);
}

#include "pswap.h"

int	ft_up_cost(t_stack **stack, int target)
{
	t_stack	*lst;
	int		i;

	i = 0;
	lst = *stack;
	while (lst)
	{
		if (lst->index != target)
		{
			i++;
			lst = lst->next;
		}
		else
			lst = NULL;
	}
	return (i);
}

#include "pswap.h"

int	ft_down_cost(t_stack **stack, int target)
{
	t_stack	*lst;
	int		i;

	i = 0;
	lst = *stack;
	while (lst && lst->index != target)
		lst = lst->next;
	if (!lst)
		return (INT_MAX);
	if (lst->index == target)
		lst = lst->next;
	while (lst && lst->index != target)
	{
		i++;
		lst = lst->next;
	}
	return (i);
}

#include "pswap.h"

int	ft_swap_test_a(t_stack **top_a)
{
	if (top_a && *top_a && (*top_a)->next)
		if ((*top_a)->index > (*top_a)->next->index)
			return (1);
	return (0);
}

#include "pswap.h"

void	ft_solve_chunks(t_stack **top_a, t_stack **top_b)
{
	int	target;

	target = (*top_b)->size -1;
	while (*top_b)
	{
		if (ft_up_cost(top_b, target) <= ft_down_cost(top_b, target))
		{
			while ((*top_b)->index != target)
				ft_move_rb(top_b, PRINT_OK);
		}
		else if (ft_up_cost(top_b, target) > ft_down_cost(top_b, target))
		{
			while ((*top_b)->index != target)
				ft_move_rrb(top_b, PRINT_OK);
		}
		ft_move_pa(top_a, top_b, PRINT_OK);
		if (ft_swap_test_a(top_a))
			ft_move_sa(top_a, PRINT_OK);
		target = target - 1;
	}
}

#include "pswap.h"

void	ft_rb_loop(t_stack **top_a, t_stack **top_b, int target, int *bonus)
{
	while ((*top_b)->index != target)
	{
		if ((*top_b)->index == target - 1)
		{
			ft_move_pa(top_a, top_b, PRINT_OK);
			*bonus += 1;
		}
		else
			ft_move_rb(top_b, PRINT_OK);
	}
}

#include "pswap.h"

void	ft_rrb_loop(t_stack **top_a, t_stack **top_b, int target, int *bonus)
{
	while ((*top_b)->index != target)
	{
		if ((*top_b)->index == target - 1)
		{
			ft_move_pa(top_a, top_b, PRINT_OK);
			*bonus += 1;
		}
		else
			ft_move_rrb(top_b, PRINT_OK);
	}
}

#include "pswap.h"

void	ft_solve_all(t_stack **top_a, t_stack **top_b)
{
	int	bonus;
	int	target;

	target = (*top_b)->size -1;
	while (*top_b)
	{
		bonus = 0;
		if (ft_up_cost(top_b, target) <= ft_down_cost(top_b, target))
			ft_rb_loop(top_a, top_b, target, &bonus);
		else if (ft_up_cost(top_b, target) > ft_down_cost(top_b, target))
			ft_rrb_loop(top_a, top_b, target, &bonus);
		ft_move_pa(top_a, top_b, PRINT_OK);
		bonus++;
		if (ft_swap_test_a(top_a))
			ft_move_sa(top_a, PRINT_OK);
		target = target - bonus;
	}
}

#include "pswap.h"

void	ft_thirds_a_in_b(t_stack **top_a, t_stack **top_b, int size, int ratio)
{
	static int	moves;
	int			cap;
	int			midcap;

	cap = size * ratio / 100 + moves;
	midcap = size * ratio / 100 / 2 + moves;
	while (moves < cap)
	{
		if ((*top_a)->index <= cap)
		{
			ft_move_pb(top_a, top_b, PRINT_OK);
			if ((*top_b)->index <= midcap)
				ft_move_rb(top_b, PRINT_OK);
			moves++;
		}
		else
			ft_move_ra(top_a, PRINT_OK);
	}
}

#include "pswap.h"

void	ft_chunk_a_in_b(t_stack **top_a, t_stack **top_b)
{
	int	step;
	int	chunk_size;
	int	b_size;

	step = 1;
	b_size = 0;
	chunk_size = (*top_a)->size / 8;
	while (step != 9)
	{
		if ((*top_a)->index < chunk_size * (step + 1))
		{
			ft_move_pb(top_a, top_b, PRINT_OK);
			if ((*top_b)->index < (chunk_size * step))
				ft_move_rb(top_b, PRINT_OK);
			b_size++;
		}
		else
			ft_move_ra(top_a, PRINT_OK);
		if (b_size == chunk_size * (step + 1))
			step += 2;
		while (step == 9 && *top_a)
			ft_move_pb(top_a, top_b, PRINT_OK);
	}
}

#include "pswap.h"

void	ft_sort(t_stack **top_a, t_stack **top_b, int *ratio)
{
	int	i;

	i = -1;
	if ((*top_a)->size <= 100)
	{
		ft_chunk_a_in_b(top_a, top_b);
		ft_solve_chunks(top_a, top_b);
	}
	else
	{
		while (i < 8)
			ft_thirds_a_in_b(top_a, top_b, ft_stack_len(top_a), ratio[++i]);
		ft_solve_all(top_a, top_b);
	}
}

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

#include "pswap.h"

int	ft_check_valid_char_only(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
	{
		if (!ft_strchr("-+0123456789 \b\t\n\v\f\r", str[i]))
			return (0);
		i++;
	}
	return (1);
}

#include "pswap.h"

int	ft_check_valid_sign(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
	{
		if (ft_strchr("+-", str[i]))
		{
			i++;
			if (!str[i] || !ft_strchr("0123456789", str[i]))
				return (0);
		}
		i++;
	}
	i = 0;
	while (str[i])
	{
		if (ft_strchr("+-", str[i]) && i && ft_strchr("0123456789", str[i - 1]))
			return (0);
		i++;
	}
	return (1);
}

#include "pswap.h"

int	ft_check_empty_arg(char *str)
{
	char	*tmp;

	tmp = NULL;
	if (!str)
		return (0);
	tmp = ft_strtrim(str, " \b\t\n\v\f\r");
	if (!tmp[0])
	{
		ft_true_free((void **)&tmp);
		return (0);
	}
	ft_true_free((void **)&tmp);
	return (1);
}

#include "pswap.h"

int	ft_check_overflow(char *str)
{
	char	**tmp;
	int		check;
	int		i;

	i = 0;
	check = 1;
	tmp = NULL;
	tmp = ft_split_set(str, " \b\t\n\v\f\r");
	while (tmp && tmp[i])
	{
		ft_atoi_safe(tmp[i], &check);
		if (!check)
		{
			ft_full_free((void **)tmp);
			return (0);
		}
		i++;
	}
	ft_full_free((void **)tmp);
	return (1);
}

#include "pswap.h"

char	***ft_disjoin_args(char **argv)
{
	char	***splited;
	int		i;

	i = 0;
	splited = NULL;
	splited = (char ***)malloc(sizeof(char **) * (ft_strslen(argv) + 1));
	if (!splited)
		return (NULL);
	splited[ft_strslen(argv)] = NULL;
	while (argv[i])
	{
		splited[i] = ft_split_set(argv[i], " \b\t\n\v\f\r");
		i++;
	}
	return (splited);
}

#include "pswap.h"

int	ft_triple_strslen(char ***strs)
{
	int	i;
	int	j;
	int	total;

	i = 0;
	j = 0;
	total = 0;
	while (strs && strs[i])
	{
		while (strs[i][j])
		{
			total++;
			j++;
		}
		j = 0;
		i++;
	}
	return (total);
}

#include "pswap.h"

void	ft_triple_free(char ***tobefreed)
{
	int	i;

	i = 0;
	while (tobefreed && tobefreed[i])
	{
		ft_full_free((void **)tobefreed[i]);
		i++;
	}
	if (tobefreed)
	{
		free(tobefreed);
		tobefreed = NULL;
	}
}

#include "pswap.h"

char **ft_strs_triple_into_double(char ***triple)
{
	char	**strs;
	int		size;
	int		i;
	int		j;
	int		x;

	i = -1;
	j = -1;
	x = -1;
	size = ft_triple_strslen(triple);
	strs = (char **)malloc(sizeof(char *) * (size + 1));
	if (!strs)
		return (NULL);
	strs[size] = NULL;
	while (triple[++i])
	{
		while (triple[i][++j])
			strs[++x] = ft_strdup(triple[i][j]);
		j = -1;
	}
	ft_triple_free(triple);
	return (strs);
}

#include "pswap.h"

int	*ft_get_parsed_tab(char **argv)
{
	char	***splited;
	char	**aligned;
	int		*tab;
	int		*ordered;

	splited = ft_disjoin_args(argv);
	aligned = ft_strs_triple_into_double(splited);
	tab = ft_strs_to_tab(ft_strslen(aligned), aligned);
	ordered = ft_sort_int_tab(tab, ft_strslen(aligned));
	if (!ft_check_dup_int(ft_strslen(aligned), ordered))
		ft_true_free((void **)&tab);
	ft_full_free((void **)aligned);
	ft_true_free((void **)&ordered);
	return (tab);
}

#include "pswap.h"

int	ft_pswap_args_check(char **argv)
{
	int	i;

	i = 0;
	while (argv[i])
	{
		if (!ft_check_valid_char_only(argv[i]))
			return (0);
		if (!ft_check_valid_sign(argv[i]))
			return (0);
		if (!ft_check_empty_arg(argv[i]))
			return (0);
		if (!ft_check_overflow(argv[i]))
			return (0);
		i++;
	}
	return (1);
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
