/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zharzi <zharzi@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 06:22:33 by zharzi            #+#    #+#             */
/*   Updated: 2022/12/27 16:48:59 by zharzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pswap.h"

typedef struct s_context {
	int		ac;
	char	**argv;
	int		*tab;
	int		*order;
}	t_context;

typedef struct s_stack {
	int				value;
	int				index;
	int				size;
	struct s_stack	*next;
	struct s_stack	*prev;
}	t_stack;
/*
typedef struct s_control {
	int	ac;
	int	max;
	int	firstthird;
	int	lastthird;
	int	pop_a;
	int	pop_ea;
	int	pop_b;
	int	pop_eb;
	int	lock;
	int	total;
}	t_control;
*/
/*
void	ft_ending_bstack(t_list **astack, t_list **bstack, t_control *val)
{
	t_list	*tmp;

	val->pop_b += val->pop_eb;
	val->pop_eb = 0;
	while (*bstack)
	{
		tmp = ft_lstlast(*bstack);
		if ((*bstack)->index < tmp->index)
			ft_move_rrb(bstack, val);
		ft_move_pa(astack, bstack, val);
		ft_swap_top_test(astack, bstack, val);
	}
}

void	ft_ending_eastack(t_list **astack, t_list **bstack, t_control *val)
{
	while (val->pop_ea)
	{
		if (!(*bstack) && val->ac > 3 && val->pop_a \
			&& ft_index_comp(ft_lstlast(*astack), *astack))
		{
			ft_move_pb(astack, bstack, val);
			while (ft_test_index(*astack, *bstack))
				ft_move_pb(astack, bstack, val);
		}
		else if (!(*bstack) && val->pop_ea)
			ft_move_rra(astack, val);
		ft_swap_top_test(astack, bstack, val);
		if (*bstack && val->pop_ea && ft_lstsize(*astack) > 1)
		{
			if (!ft_index_comp(ft_lstlast(*astack), *bstack) \
				&& ((ft_lstsize(*bstack) > 1 && ft_index_comp(*bstack, \
				ft_lstlast(*bstack))) || ft_lstsize(*bstack) == 1))
				ft_get_from_b(astack, bstack, val);
			else if (!ft_index_comp(ft_lstlast(*astack), *bstack))
				ft_get_from_eb(astack, bstack, val);
			ft_move_rra(astack, val);
		}
		ft_swap_top_test(astack, bstack, val);
	}
}

t_control	ft_fill_controlval(int ac)
{
	t_control	values;

	values.ac = ac;
	values.max = ac - 1;
	values.firstthird = (ac - 1) / 3;
	values.lastthird = (ac - 1) * 2 / 3;
	values.pop_a = ac;
	values.lock = 0;
	values.pop_ea = 0;
	values.pop_b = 0;
	values.pop_eb = 0;
	return (values);
}

t_list	*ft_first_estack(t_list **stack, int pop)
{
	t_list	*tmp;

	tmp = *stack;
	while (pop)
	{
		pop--;
		tmp = tmp->next;
	}
	return (tmp);
}

void	ft_get_back_eb(t_list **astack, t_list **bstack, t_control *val)
{
	t_list	*tmp1;
	t_list	*tmp2;

	tmp1 = NULL;
	tmp2 = NULL;
	if (val->pop_a && *bstack)
	{
		tmp1 = *astack;
		tmp2 = ft_lstlast(*bstack);
	}
	if (ft_test_index(tmp1, tmp2))
	{
		ft_move_rrb(bstack, val);
		ft_move_pa(astack, bstack, val);
		ft_swap_top_test(astack, bstack, val);
	}
}

void	ft_get_back_if(t_list **astack, t_list **bstack, t_control *val)
{
	t_list	*tmp1;
	t_list	*tmp2;

	tmp1 = *astack;
	tmp2 = *bstack;
	if (tmp1 && tmp2 && val->pop_a && (val->pop_b || val->pop_eb))
	{
		if (ft_test_index(tmp1, tmp2))
		{
			ft_move_pa(astack, bstack, val);
			ft_swap_top_test(astack, bstack, val);
		}
		else if (!ft_test_index(tmp1, tmp2))
			ft_get_back_eb(astack, bstack, val);
		else if (tmp2)
			ft_ending_bstack(astack, bstack, val);
	}
	else if ((!tmp1 || !val->pop_a) && tmp2)
		ft_ending_bstack(astack, bstack, val);
}

int	ft_homing_booster(t_list **astack, t_list **bstack, t_control *val)
{
	t_list	*tmp;
	int		check;

	check = 0;
	if (*astack)
	{
		tmp = ft_lstlast(*astack);
		while (val->ac > 4 && tmp && !ft_is_lock(tmp, astack, val) \
		&& tmp->index <= val->firstthird)
		{
			ft_move_rra(astack, val);
			ft_swap_top_test(astack, bstack, val);
			check = 1;
			tmp = ft_lstlast(*astack);
		}
		ft_put_end(astack, val, 1);
		if (!val->lock && (*astack)->index == val->max)
			ft_move_ra(astack, val);
	}
	return (check);
}

void	ft_homing_max(t_list **astack, t_list **bstack, t_control *val)
{
	t_list		*tmp;
	int			rank;

	ft_homing_booster(astack, bstack, val);
	tmp = *astack;
	rank = 0;
	while (tmp && tmp->index != val->max && ++rank)
		tmp = tmp->next;
	if (!val->lock && rank >= ft_lstsize(*astack) / 2)
	{
		val->pop_a = rank;
		val->lock++;
		val->max--;
		val->pop_ea = \
		val->ac - (val->pop_a + val->lock) - (val->pop_b + val->pop_eb);
	}
}

int	ft_index_comp(t_list *elem1, t_list *elem2)
{
	if (elem1 && elem2 && elem1->index > elem2->index)
		return (1);
	return (0);
}

int	ft_is_lock(t_list *elem, t_list **astack, t_control *val)
{
	t_list	*tmp;
	int		pop;

	pop = val->pop_a;
	tmp = *astack;
	if (pop && val->lock && tmp)
	{
		while (tmp && pop--)
			tmp = tmp->next;
		pop = val->lock;
		while (tmp && pop)
		{
			if (tmp == elem)
				return (1);
			tmp = tmp->next;
			pop--;
		}
	}
	return (0);
}

int	ft_lock_elem(t_list **astack, t_control **val)
{
	t_list	*tmp1;

	if ((*val)->pop_a && (*val)->lock)
	{
		tmp1 = *astack;
		while (tmp1->next && !ft_is_lock(tmp1->next, astack, *val))
			tmp1 = tmp1->next;
		if (ft_is_lock(tmp1->next, astack, *val))
		{
			if (ft_test_index(tmp1, tmp1->next) == -1)
			{
				(*val)->pop_a--;
				(*val)->lock++;
				(*val)->max--;
				return (1);
			}
		}
	}
	return (0);
}

void	ft_move_pa(t_list **astack, t_list **bstack, t_control *val)
{
	t_list	*tmp1;

	if (*bstack)
	{
		tmp1 = *bstack;
		*bstack = (*bstack)->next;
		tmp1->next = *astack;
		*astack = tmp1;
		if (val->pop_b)
			val->pop_b--;
		else
			val->pop_eb--;
		val->pop_a++;
		val->total++;
		ft_printf("pa\n");
	}
}

void	ft_move_pb(t_list **astack, t_list **bstack, t_control *val)
{
	t_list	*tmp1;

	if (*astack)
	{
		tmp1 = *astack;
		*astack = (*astack)->next;
		tmp1->next = *bstack;
		*bstack = tmp1;
		if (val->pop_a)
			val->pop_a--;
		else
			val->pop_ea--;
		val->pop_b++;
		val->total++;
		ft_printf("pb\n");
	}
}

void	ft_ra_details(t_list **astack)
{
	t_list	*tmp1;
	t_list	*tmp2;

	if (*astack && (*astack)->next)
	{
		tmp2 = *astack;
		*astack = (*astack)->next;
		tmp2->next = NULL;
		tmp1 = *astack;
		while (tmp1 && tmp1->next)
			tmp1 = tmp1->next;
		tmp1->next = tmp2;
	}
}

void	ft_move_ra(t_list **astack, t_control *val)
{
	if (*astack && (*astack)->next)
		ft_ra_details(astack);
	if (val->pop_a)
	{
		val->pop_a--;
		val->pop_ea++;
		val->total++;
	}
	ft_printf("ra\n");
}

void	ft_rb_details(t_list **bstack)
{
	t_list	*tmp1;
	t_list	*tmp2;

	if (*bstack && (*bstack)->next)
	{
		tmp2 = *bstack;
		*bstack = (*bstack)->next;
		tmp2->next = NULL;
		tmp1 = *bstack;
		while (tmp1 && tmp1->next)
			tmp1 = tmp1->next;
		tmp1->next = tmp2;
	}
}

void	ft_move_rb(t_list **bstack, t_control *val)
{
	if (*bstack && (*bstack)->next)
		ft_rb_details(bstack);
	if (val->pop_b)
	{
		val->pop_b--;
		val->pop_eb++;
		val->total++;
	}
	ft_printf("rb\n");
}

void	ft_rra_details(t_list **astack)
{
	t_list	*tmp1;
	t_list	*tmp2;

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
	}
}

void	ft_move_rra(t_list **astack, t_control *val)
{
	if (*astack && (*astack)->next)
	{
		ft_rra_details(astack);
		if (val->pop_ea)
		{
			val->pop_a++;
			val->pop_ea--;
		}
		val->total++;
		ft_printf("rra\n");
	}
}

void	ft_rrb_details(t_list **bstack)
{
	t_list	*tmp1;
	t_list	*tmp2;

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
	}
}

void	ft_move_rrb(t_list **bstack, t_control *val)
{
	if (*bstack && (*bstack)->next)
	{
		ft_rrb_details(bstack);
		if (val->pop_eb)
		{
			val->pop_b++;
			val->pop_eb--;
		}
		val->total++;
		ft_printf("rrb\n");
	}
}

void	ft_move_rr(t_list **astack, t_list **bstack, t_control *val)
{
	if (*astack && (*astack)->next && *bstack && (*bstack)->next)
	{
		ft_ra_details(astack);
		ft_rb_details(bstack);
		if (val->pop_a)
		{
			val->pop_a--;
			val->pop_ea++;
		}
		if (val->pop_b)
		{
			val->pop_b--;
			val->pop_eb++;
			val->total++;
		}
		ft_printf("rr\n");
	}
}

void	ft_move_rrr(t_list **astack, t_list **bstack, t_control *val)
{
	if (*astack && (*astack)->next && *bstack && (*bstack)->next)
	{
		ft_rra_details(astack);
		ft_rrb_details(bstack);
		if (val->pop_ea)
		{
			val->pop_a++;
			val->pop_ea--;
		}
		if (val->pop_eb)
		{
			val->pop_b++;
			val->pop_eb--;
		}
		val->total++;
		ft_printf("rrr\n");
	}
}

void	ft_move_sa(t_list **astack, t_control *val)
{
	t_list	*elem3;
	t_list	*elem2;

	if (*astack && (*astack)->next)
	{
		elem3 = (*astack)->next;
		elem2 = elem3;
		elem3 = elem3->next;
		elem2->next = *astack;
		(*astack)->next = elem3;
		*astack = elem2;
		val->total++;
		ft_printf("sa\n");
	}
}

void	ft_get_from_ea(t_list **astack, t_control *val)
{
	ft_move_rra(astack, val);
}

void	ft_get_from_b(t_list **astack, t_list **bstack, t_control *val)
{
	ft_move_pa(astack, bstack, val);
}

void	ft_get_from_eb(t_list **astack, t_list **bstack, t_control *val)
{
	ft_move_rrb(bstack, val);
	ft_move_pa(astack, bstack, val);
}

void	ft_move_sb(t_list **bstack, t_control *val)
{
	t_list	*elem3;
	t_list	*elem2;

	if (*bstack && (*bstack)->next)
	{
		elem3 = (*bstack)->next;
		elem2 = elem3;
		elem3 = elem3->next;
		elem2->next = *bstack;
		(*bstack)->next = elem3;
		*bstack = elem2;
		val->total++;
		ft_printf("sb\n");
	}
}

void	ft_push_to_ea(t_list **astack, t_control *val)
{
	ft_move_ra(astack, val);
}

void	ft_push_to_b(t_list **astack, t_list **bstack, t_control *val)
{
	ft_move_pb(astack, bstack, val);
}

void	ft_push_to_eb(t_list **astack, t_list **bstack, t_control *val)
{
	ft_move_pb(astack, bstack, val);
	if (*bstack && (*bstack)->next && \
	(*bstack)->index - 1 != (*bstack)->next->index)
		ft_move_rb(bstack, val);
	else
	{
		val->pop_b--;
		val->pop_eb++;
	}
}

void	ft_move_ss(t_list **astack, t_list **bstack, t_control *val)
{
	t_list	*elem3;
	t_list	*elem2;

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
		val->total++;
		ft_printf("ss\n");
	}
}


int	ft_pswap_final(t_list **astack, t_list **bstack, t_control *val)
{
	t_list	*tmp1;
	t_list	*tmp2;

	tmp1 = *astack;
	tmp2 = *bstack;
	if ((!tmp2 || ft_stack_check_order(tmp2, val->pop_b + val->pop_eb, 1)) \
	&& ft_stack_check_order(tmp1, val->pop_a + val->lock + val->pop_ea, -1))
		return (1);
	return (0);
}



void	ft_put_end(t_list **astack, t_control *val, int position)
{
	t_list	*tmp;
	int		series;

	series = ft_series_length(*astack, -1, position);
	tmp = ft_lst_find_one(*astack, position + series - 2);
	if (tmp->index == val->ac - 1 && tmp != ft_lstlast(*astack))
	{
		while (series > 0)
		{
			ft_move_ra(astack, val);
			series--;
		}
	}
}

int	ft_series_length(t_list *stack, int order, int position)
{
	int	length;

	length = 0;
	while (stack && --position)
		stack = stack->next;
	if (!stack)
		return (length);
	else
		length++;
	while (stack->next && ft_test_index(stack, stack->next) == order)
	{
		stack = stack->next;
		length++;
	}
	return (length);
}

void	ft_small_end(t_list **astack, t_list **bstack, t_control *val)
{
	if (val->pop_a > 1 && !ft_pswap_final(astack, bstack, val))
	{
		ft_move_pb(astack, bstack, val);
		ft_swap_test_b(astack, bstack, val);
		ft_small(astack, bstack, val);
	}
	else if (!ft_pswap_final(astack, bstack, val))
	{
		while (val->pop_b && !ft_pswap_final(astack, bstack, val))
		{
			if (val->pop_a && !ft_index_comp(*astack, ft_lstlast(*bstack)))
				ft_push_to_eb(astack, bstack, val);
			while (*bstack && !ft_pswap_final(astack, bstack, val))
				ft_get_back_if(astack, bstack, val);
			if (val->pop_a < 2)
				ft_ending_bstack(astack, bstack, val);
			ft_small(astack, bstack, val);
		}
	}
}

void	ft_small(t_list **astack, t_list **bstack, t_control *val)
{
	if (ft_pswap_final(astack, bstack, val))
		return ;
	ft_put_end(astack, val, 1);
	if (!val->lock && !ft_pswap_final(astack, bstack, val))
		ft_homing_max(astack, bstack, val);
	while (ft_lock_elem(astack, &val))
		;
	if (val->lock && val->pop_ea && !ft_pswap_final(astack, bstack, val))
		ft_ending_eastack(astack, bstack, val);
	if (!ft_pswap_final(astack, bstack, val))
		ft_swap_test_b(astack, bstack, val);
	ft_small_end(astack, bstack, val);
}

int	ft_stack_check_order(t_list *stack, int pop, int order)
{
	if (!stack)
		return (order);
	while (stack && pop > 1)
	{
		if (ft_test_index(stack, stack->next) != order)
			return (0);
		stack = stack->next;
		pop--;
	}
	return (order);
}

int	ft_swap_test_b(t_list **astack, t_list **bstack, t_control *val)
{
	t_list	*tmp1;
	t_list	*tmp2;
	int		check;

	tmp1 = NULL;
	check = 0;
	if (*bstack && (*bstack)->next)
	{
		tmp1 = *bstack;
		tmp2 = ft_lstlast(tmp1);
	}
	if (tmp1 && !ft_index_comp(tmp1, tmp2))
	{
		ft_move_rrb(bstack, val);
		check = 1;
	}
	ft_swap_top_test(astack, bstack, val);
	return (check);
}

void	ft_swap_top_test(t_list **astack, t_list **bstack, t_control *val)
{
	t_list	*ta1;
	t_list	*tb1;

	ta1 = NULL;
	tb1 = NULL;
	ft_lock_elem(astack, &val);
	if (val->pop_a > 1)
	{
		if (*astack && (*astack)->next)
			ta1 = *astack;
		if (*bstack && (*bstack)->next)
			tb1 = *bstack;
		if (ta1->index == val->ac - 1)
			ft_move_ra(astack, val);
		else if (ta1 && tb1 && ft_index_comp(ta1, ta1->next) \
		&& !ft_index_comp(tb1, tb1->next))
			ft_move_ss(astack, bstack, val);
		else if (ta1 && ta1->next && ft_index_comp(ta1, ta1->next))
			ft_move_sa(astack, val);
		else if (tb1 && tb1->next && !ft_index_comp(tb1, tb1->next))
			ft_move_sb(bstack, val);
	}
}

int	ft_test_index(t_list *tmp1, t_list *tmp2)
{
	if (tmp1 && tmp2 && tmp1->index == (tmp2->index) - 1)
		return (-1);
	if (tmp1 && tmp2 && tmp1->index == (tmp2->index) + 1)
		return (1);
	return (0);
}

void	ft_main_pattern(t_list **astack, t_list **bstack, t_control *val)
{
	int	i;
	int	rank;

	i = 0;
	rank = 0;
	while (!ft_pswap_final(astack, bstack, val))
	{
		while (i < val->ac && !ft_pswap_final(astack, bstack, val))
		{
			if (((*astack)->index >> rank) & 0x1)
				ft_move_ra(astack, val);
			else
				ft_move_pb(astack, bstack, val);
			i++;
		}
		i = 0;
		while (*bstack)
			ft_move_pa(astack, bstack, val);
		rank++;
	}
}

void	ft_push_swap(int ac, t_list **astack, t_list **bstack)
{
	t_control	val;

	if (ac == 1)
		return ;
	val = ft_fill_controlval(ac);
	if (val.ac <= 5 && !ft_pswap_final(astack, bstack, &val))
		ft_small(astack, bstack, &val);
	else if (!ft_pswap_final(astack, bstack, &val))
		ft_main_pattern(astack, bstack, &val);
	ft_ending_bstack(astack, bstack, &val);
}

int	ft_pswap_check_args(int *ac, char *full)
{
	int	i;

	i = 0;
	*ac = 0;
	if (!full)
		return (0);
	while (full[i])
	{
		if (full[i] && (full[i] == ' ' || ((full[i] == '+' || \
		full[i] == '-') && (full[i + 1] && ft_isdigit(full[i + 1])))))
			i++;
		else if (full[i] && ft_isdigit(full[i]))
		{
			*ac += 1;
			while (full[i] && ft_isdigit(full[i]))
				i++;
			if (full[i] && full[i] != ' ')
				return (0);
		}
		else
			return (0);
	}
	return (1);
}

char	*ft_pswap_join(char **av)
{
	int		a;
	int		i;
	char	*full;
	char	*tmp;

	i = -1;
	a = 0;
	full = NULL;
	while (av && av[++i])
	{
		tmp = full;
		full = ft_strjoin(full, av[i]);
		if (tmp)
			ft_true_free(tmp);
		tmp = full;
		full = ft_strjoin(full, " ");
		if (tmp)
			ft_true_free(tmp);
		a++;
	}
	return (full);
}

int	ft_pswap_intfinder(char **av)
{
	int	i;
	int	j;
	int	x;

	i = -1;
	j = -1;
	x = 0;
	while (av[++i])
	{
		while (av[i][++j] != '\0')
			if (ft_isdigit(av[i][j]))
				x++;
		if (!x)
			return (0);
		x = 0;
		j = -1;
	}
	return (1);
}

int	*ft_pswap_parsing(int *ac, char **av)
{
	int		i;
	char	*full;
	char	**finalcut;
	int		*tab;

	i = -1;
	tab = NULL;
	if (*ac < 2 || !av || !ft_pswap_intfinder(av))
		return (NULL);
	while (++i < (*ac - 1))
	{
		if (av[i][0] == '\0')
			return (NULL);
	}
	full = ft_pswap_join(av);
	if (!ft_pswap_check_args(ac, full))
		return (ft_true_free(full), NULL);
	finalcut = ft_split(full, ' ');
	tab = ft_strs_to_tab(*ac, finalcut);
	ft_true_free(full);
	ft_full_free((void **)finalcut);
	return (tab);
}
*/

void	ft_push_swap(void)
{
	;
}

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

char **ft_strs_triple_into_double(char ***triple)
{
	char	**strs;
	int		size;
	int		i;
	int		j;
	int		x;

	i = -1;
	j = 0;
	x = 0;
	size = ft_triple_strslen(triple);
	strs = (char **)malloc(sizeof(char *) * (size + 1));
	if (!strs)
		return (NULL);
	strs[size] = NULL;
	while (triple[++i])
	{
		while (triple[i][++j])
		{
			strs[x] = ft_strdup(triple[i][j]);
			x++;
		}
		j = -1;
	}
	ft_triple_free(triple);
	return (strs);
}

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

int	main(int ac, char **argv)
{
	int	*tab;

	tab = NULL;
	if (ac == 1)
		return (0);
	if (ft_pswap_args_check(argv + 1))
	{
		tab = ft_get_parsed_tab(argv);
		if (tab)
		{
			ft_push_swap();
			ft_true_free((void **)&tab);
		}
		else
			write(2, "Error\n", 6);
	}
	else
		write(2, "Error\n", 6);
	return (0);
}

/*
int	main(int ac, char *av[])
{
//	int		*tabav;
//	int		*sortedav;
//	t_list	*listav;
//	t_list	*bstack;

	if (ac == 1)
		return (0);
	//bstack = NULL;
	//tabav = ft_pswap_parsing(&ac, av + 1);
	//sortedav = ft_sort_int_tab(tabav, ac);
	//if (!tabav || !ft_check_dup_int(ac, sortedav))
	//{
	//	if (!ft_check_dup_int(ac, sortedav))
	//	{
	//		ft_true_free(sortedav);
	//		ft_true_free(tabav);
	//	}
	//	write(2, "Error\n", 6);
	//	return (1);
	//}
	//listav = ft_tab_to_lst(ac, tabav);
	//ft_index_intlist(&listav, sortedav, ac);
	//ft_push_swap(ac, &listav, &bstack);
	//return (ft_true_free(tabav), ft_true_free(sortedav), \
	//	ft_full_free_lst(&listav), 0);
	(void)av;
}
*/
