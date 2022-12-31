/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_stack_a.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zharzi <zharzi@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/31 11:58:22 by zharzi            #+#    #+#             */
/*   Updated: 2022/12/31 12:32:45 by zharzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
