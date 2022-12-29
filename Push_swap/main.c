/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zharzi <zharzi@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 06:22:33 by zharzi            #+#    #+#             */
/*   Updated: 2022/12/29 23:31:16 by zharzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pswap.h"

#define ASCENDING -1
#define DESCENDING 1

typedef struct s_stack {
	int				size;
	int				value;
	int				index;
	struct s_stack	*next;
}	t_stack;

int	g_counter = 0;

//////////////////////////////////////////////////////////////////

void	ft_move_pa(t_stack **astack, t_stack **bstack)
{
	t_stack	*tmp1;

	if (*bstack)
	{
		tmp1 = *bstack;
		*bstack = (*bstack)->next;
		tmp1->next = *astack;
		*astack = tmp1;
		g_counter++;
		ft_printf("pa\t%d\n", g_counter);
		//ft_printf("pa\n");
	}
}

void	ft_move_pb(t_stack **astack, t_stack **bstack)
{
	t_stack	*tmp1;

	if (*astack)
	{
		tmp1 = *astack;
		*astack = (*astack)->next;
		tmp1->next = *bstack;
		*bstack = tmp1;
		g_counter++;
		ft_printf("pb\t%d\n", g_counter);
		// ft_printf("pb\n");
	}
}

void	ft_move_ra(t_stack **astack)
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
		g_counter++;
		ft_printf("ra\t%d\n", g_counter);
		// ft_printf("ra\n");
	}
}

void	ft_move_rb(t_stack **bstack)
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
		g_counter++;
		ft_printf("rb\t%d\n", g_counter);
		// ft_printf("rb\n");
	}
}

void	ft_move_rra(t_stack **astack)
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
		g_counter++;
		ft_printf("rra\t%d\n", g_counter);
		// ft_printf("rra\n");
	}
}

void	ft_move_rrb(t_stack **bstack)
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
		g_counter++;
		ft_printf("rrb\t%d\n", g_counter);
		// ft_printf("rrb\n");
	}
}

void	ft_move_rr(t_stack **astack, t_stack **bstack)
{
	t_stack	*tmp1;
	t_stack	*tmp2;

	if (*astack && (*astack)->next && *bstack && (*bstack)->next)
	{
		tmp2 = *astack;
		*astack = (*astack)->next;
		tmp2->next = NULL;
		tmp1 = *astack;
		while (tmp1 && tmp1->next)
			tmp1 = tmp1->next;
		tmp1->next = tmp2;
		tmp2 = *bstack;
		*bstack = (*bstack)->next;
		tmp2->next = NULL;
		tmp1 = *bstack;
		while (tmp1 && tmp1->next)
			tmp1 = tmp1->next;
		tmp1->next = tmp2;
		g_counter++;
		ft_printf("rr\t%d\n", g_counter);
		// ft_printf("rr\n");
	}
}

void	ft_move_rrr(t_stack **astack, t_stack **bstack)
{
	t_stack	*tmp1;
	t_stack	*tmp2;

	if (*astack && (*astack)->next && *bstack && (*bstack)->next)
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
		tmp2 = *bstack;
		while (tmp2 && tmp2->next)
		{
			tmp1 = tmp2;
			tmp2 = tmp2->next;
		}
		tmp1->next = NULL;
		tmp2->next = *bstack;
		*bstack = tmp2;
		g_counter++;
		ft_printf("rrr\t%d\n", g_counter);
		// ft_printf("rrr\n");
	}
}

void	ft_move_sa(t_stack **astack)
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
		g_counter++;
		ft_printf("sa\t%d\n", g_counter);
		// ft_printf("sa\n");
	}
}

void	ft_move_sb(t_stack **bstack)
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
		g_counter++;
		ft_printf("sb\t%d\n", g_counter);
		// ft_printf("sb\n");
	}
}

void	ft_move_ss(t_stack **astack, t_stack **bstack)
{
	t_stack	*elem3;
	t_stack	*elem2;

	if (*astack && (*astack)->next && *bstack && (*bstack)->next)
	{
		elem3 = (*astack)->next;
		elem2 = elem3;
		elem3 = elem3->next;
		elem2->next = *astack;
		(*astack)->next = elem3;
		*astack = elem2;
		elem3 = (*bstack)->next;
		elem2 = elem3;
		elem3 = elem3->next;
		elem2->next = *bstack;
		(*bstack)->next = elem3;
		*bstack = elem2;
		g_counter++;
		ft_printf("ss\t%d\n", g_counter);
		// ft_printf("ss\n");
	}
}

//////////////////////////////////////////////////////////////////

int	ft_test_index(t_stack *elem1, t_stack *elem2)
{
	if (elem1 && elem2 && elem1->index == (elem2->index) - 1)
		return (ASCENDING);
	if (elem1 && elem2 && elem1->index == (elem2->index) + 1)
		return (DESCENDING);
	return (0);
}

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

int	ft_get_index(int value, int *ordered)//done
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

void	ft_init_stack_a(t_stack **a, int *tab, int size)//done
{
	t_stack	*tmp;
	int	*ordered;
	int	i;

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

t_stack	*ft_shape_stack_lst(int size)//done
{
	t_stack *elem;

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

void	ft_free_stack(t_stack **stack)//done
{
	t_stack *tmp1;
	t_stack *tmp2;

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

t_stack *ft_get_last_elem(t_stack *lst)//done
{
	t_stack *tmp;

	tmp = NULL;
	while (lst)
	{
		tmp = lst;
		lst = lst->next;
	}
	return (tmp);
}

void	ft_drain_b(t_stack **astack, t_stack **bstack)//done
{
	while (*bstack)
	{
		ft_move_pa(astack, bstack);
	}
}

//////////////////////////////////////////////////////////////////

void	ft_show_stack(t_stack **lst)//done
{
	t_stack *tmp;

	tmp = *lst;
	while (tmp)
	{
		ft_printf("[%d]", tmp->index);
		tmp = tmp->next;
	}
	ft_printf("\n");
}

void	ft_show_it_all(t_stack **top_a, t_stack **top_b)//done
{
	ft_show_stack(top_b);
	ft_printf("\n");
	ft_show_stack(top_a);
	ft_printf("-------------------------------------------------------------");
	ft_printf("\n");
}

//////////////////////////////////////////////////////////////////

void	ft_solve_b_in_a(t_stack **top_a, t_stack **top_b)
{
	;
}

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
			ft_move_pb(top_a, top_b);
			if ((*top_b)->index < (chunk_size * step))
				ft_move_rb(top_b);
			b_size++;
		}
		else
			ft_move_ra(top_a);
		if (b_size == chunk_size * (step + 1))
		{///////////////////////////////////////
			step += 2;
			ft_show_it_all(top_a, top_b);///////////////////////
		}/////////////////////////////////////
		while (step == 9 && *top_a)
			ft_move_pb(top_a, top_b);
		usleep(1000);/////////////////////////////////////////
	}
}

void	ft_sort_trio(t_stack **top_a)
{
	t_stack *tmp;

	if ((*top_a)->index == (*top_a)->size - 1)
		ft_move_ra(top_a);
	tmp = ft_get_last_elem(*top_a);
	if (!ft_check_stack_order(*top_a, ASCENDING) && tmp->index != tmp->size - 1)
		ft_move_rra(top_a);
	tmp = ft_get_last_elem(*top_a);
	if (!ft_check_stack_order(*top_a, ASCENDING) && tmp->index == tmp->size - 1)
		ft_move_sa(top_a);
}

void	ft_sort_quartet(t_stack **top_a, t_stack **top_b)
{
	t_stack	*tmp;

	tmp = ft_get_last_elem(*top_a);
	if (!ft_check_stack_order(*top_a, ASCENDING) && tmp->index == 0)
		ft_move_rra(top_a);
	while (!ft_check_stack_order(*top_a, ASCENDING) && (*top_a)->index != 0)
	{
		ft_move_ra(top_a);
		tmp = ft_get_last_elem(*top_a);
	}
	if (!ft_check_stack_order(*top_a, ASCENDING) && (*top_a)->index == 0)
	{
		ft_move_pb(top_a, top_b);
		ft_sort_trio(top_a);
	}
}

void	ft_sort_quintet(t_stack **top_a, t_stack **top_b)
{
	t_stack	*tmp;
	int		n;

	n = 0;
	tmp = ft_get_last_elem(*top_a);
	while (n != 2 && !ft_check_stack_order(*top_a, ASCENDING))
	{
		if (tmp->index == 0 || tmp->index == 1)
			ft_move_rra(top_a);
		if ((*top_a)->index == 0 || (*top_a)->index == 1)
		{
			ft_move_pb(top_a, top_b);
			n++;
		}
		else
			ft_move_ra(top_a);
		tmp = ft_get_last_elem(*top_a);
	}
	if (!ft_check_stack_order(*top_b, DESCENDING))
		ft_move_sb(top_b);
	ft_sort_trio(top_a);
}


void	ft_sort_more(t_stack **top_a, t_stack **top_b)
{
	ft_chunk_a_in_b(top_a, top_b);
	ft_solve_b_in_a(top_a, top_b);
}

//////////////////////////////////////////////////////////////////

void	ft_push_swap(int *tab, int size)//done
{
	t_stack **top_a;
	t_stack **top_b;
	t_stack *a;
	t_stack *b;

	a = ft_shape_stack_lst(size);
	b = NULL;
	ft_init_stack_a(&a, tab, size);
	top_a = &a;
	top_b = &b;
	if (size > 1 && !ft_check_stack_order(a, ASCENDING))
	{
		ft_show_it_all(top_a, top_b);
		if (size == 2)
			ft_move_sa(top_a);
		else if (size == 3)
			ft_sort_trio(top_a);
		else if (size == 4)
			ft_sort_quartet(top_a, top_b);
		else if (size == 5)
			ft_sort_quintet(top_a, top_b);
		else
			ft_sort_more(top_a, top_b);
		//ft_drain_b(top_a, top_b);
		ft_show_it_all(top_a, top_b);
	}
	ft_printf("final\t%d\n", g_counter);
	ft_free_stack(top_a);
	ft_free_stack(top_b);
}

/////////////////////////////////////////////////////////////////

int	ft_check_valid_char_only(char *str)//done
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

int	ft_check_valid_sign(char *str)//done
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

int	ft_check_empty_arg(char *str)//done
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

int	ft_check_overflow(char *str)//done
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

char	***ft_disjoin_args(char **argv)//done
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

int	ft_triple_strslen(char ***strs)//done
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

void	ft_triple_free(char ***tobefreed)//done
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

char **ft_strs_triple_into_double(char ***triple)//done
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

int	*ft_get_parsed_tab(char **argv)//done
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

int	ft_pswap_args_check(char **argv)//done
{
	int		i;

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

////////////////////////////////////////////////////////////////

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

//4 derniers bulletins de salaires avant pole emploi et attestation sur l'honneur
//precisant date de dernier jour de travail de l'arret maladie
//envoi via depot doc
