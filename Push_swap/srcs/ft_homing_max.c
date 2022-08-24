/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_homing_max.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zharzi <zharzi@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/17 22:43:22 by zharzi            #+#    #+#             */
/*   Updated: 2022/08/24 21:16:58 by zharzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pswap.h"

int	ft_homing_booster(t_list **astack, t_list **bstack, t_control *val)
{
	t_list	*tmp;
	int		check;

	ft_printf("\thoming booster\n");
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
		ft_pswap_view(astack, bstack, val);
		/*
		if (!val->lock && (*astack)->index == val->max)
		{
			ft_move_ra(astack, val);
			//val->max--;
		}*/
	}
	return (check);
}

void	ft_homing_max(t_list **astack, t_list **bstack, t_control *val)
{
	t_list		*tmp;
//	t_control	buff;
	int			rank;

	ft_printf("\thoming max\n");
	ft_homing_booster(astack, bstack, val);

	tmp = *astack;
	rank = 0;
	while (tmp && tmp->index != val->max && ++rank)
		tmp = tmp->next;
//	buff = *val;
	if (!val->lock && rank > ft_lstsize(*astack) * 0.4)
	{
		val->pop_a = rank;
		val->lock++;
		val->max--;
		val->pop_ea = \
		val->ac - (val->pop_a + val->lock) - (val->pop_b + val->pop_eb);
	}
	/*
	if (val->pop_ea > val->pop_a * 1.5)/////////////////
	{
		*val = buff;
		ft_pswap_distri(astack, bstack, val);//new
		ft_small(astack, bstack, val);//new
	}*/
	ft_pswap_view(astack, bstack, val);//new
}
/*
void	ft_homing_max(t_list **astack, t_list **bstack, t_control *val)
{
	t_list		*tmp;
	int			rank;
	int			popa;
	int			popea;

	ft_printf("\thoming max\n");
	ft_homing_booster(astack, bstack, val);
	tmp = *astack;
	rank = 0;
	while (tmp && tmp->index != val->max && ++rank)
		tmp = tmp->next;
	popa = val->pop_a;
	popea = val->pop_ea;
	val->pop_a = rank;
	rank = val->lock;
	val->lock++;
	//val->max--;
	val->pop_ea = \
	val->ac - (val->pop_a + val->lock) - (val->pop_b + val->pop_eb);
	if (val->pop_ea > val->pop_a * 1.5)
	{
		val->pop_a = popa;
		val->pop_ea = popea;
		val->lock = rank;
	//	val->max++;
		ft_pswap_distri(astack, bstack, val);//new
		ft_small(astack, bstack, val);//new
	}
	ft_pswap_view(astack, bstack, val);//new
}
*/
/*24aug22
int	ft_homing_booster(t_list **astack, t_list **bstack, t_control *val)
{
	t_list	*tmp;
	int		check;

	ft_printf("\thoming booster\n");
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
		if (!val->lock && (*astack)->index == val->max)
		{
			ft_move_ra(astack, val);
			val->max--;
		}
	}
	return (check);
}

void	ft_homing_max(t_list **astack, t_list **bstack, t_control *val)
{
	t_list		*tmp;
	t_control	buff;
	int			rank;

	ft_printf("\thoming max\n");
	ft_homing_booster(astack, bstack, val);
	tmp = *astack;
	rank = 0;
	while (tmp && tmp->index != val->max && ++rank)
		tmp = tmp->next;
	buff = *val;
	val->pop_a = rank;
	val->lock++;//gros delire
	val->max--;
	val->pop_ea = \
	val->ac - (val->pop_a + val->lock) - (val->pop_b + val->pop_eb);
	if (val->pop_ea > val->pop_a * 1.5)/////////////////
	{
		*val = buff;
		ft_pswap_distri(astack, bstack, val);//new
		ft_small(astack, bstack, val);//new
	}
	ft_pswap_view(astack, bstack, val);//new
}
*/
