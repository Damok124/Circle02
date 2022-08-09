/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zharzi <zharzi@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 06:22:33 by zharzi            #+#    #+#             */
/*   Updated: 2022/08/09 23:54:30 by zharzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pswap.h"

void	ft_get_thirds(t_list **astack, t_list *elem, t_control	**val, int ac)
{
	t_list		*tmpl;
	t_control	*tmpv;
	int			position;

	position = 0;
	tmpl = *astack;
	while (tmpl)
	{
		if (tmpl != elem)
		{
			if (*(int *)elem->content > *(int *)tmpl->content)
				position++;
		}
		tmpl = tmpl->next;
	}
	position = ac / position;
	tmpv = *val;
	if (position == 33 && *(int *)elem->content > (*tmpv).firstthird)
		(*tmpv).firstthird = *(int *)elem->content;
	if (position == 66 && *(int *)elem->content > (*tmpv).lastthird)
		(*tmpv).lastthird = *(int *)elem->content;
}

t_control	*ft_fill_controlval(t_control **values, int ac, t_list **astack)
{
	t_list		*tmp;

	(*values)->ac = ac;
	(*values)->min = INT_MAX;
	(*values)->max = INT_MIN;
	tmp = *astack;
	while (tmp)
	{
		if ((*values)->min > *(int *)tmp->content)
			(*values)->min = *(int *)tmp->content;
		if ((*values)->max < *(int *)tmp->content)
			(*values)->max = *(int *)tmp->content;
		ft_get_thirds(astack, tmp, values, ac);
		tmp = tmp->next;
	}
	return (*values);
}

void	ft_push_swap(int ac, t_list **astack, t_list **bstack)
{
	static t_control	*values;

	values = ft_fill_controlval(&values, ac, astack);
	(void)bstack;//reste a tester si la struct values est correctement remplie
}

int	main(int ac, char *av[])
{
	int		*tabav;
	int		*sortedav;
	t_list	*listav;
	t_list	*bstack;

	bstack = NULL;
	tabav = ft_pswap_parsing(&ac, av + 1);
	sortedav = ft_sort_int_tab(tabav, ac);
	if (!tabav || !ft_check_dup_int(ac, sortedav))
	{
		if (!ft_check_dup_int(ac, sortedav))
		{
			ft_true_free(sortedav);
			ft_true_free(tabav);
		}
		write(2, "Error\n", 6);
		return (1);
	}
	listav = ft_tab_to_lst(ac, tabav);
	ft_push_swap(ac, &listav, &bstack);
	ft_true_free(tabav);
	ft_true_free(sortedav);
	ft_full_free_lst(&listav);
	return (0);
}
