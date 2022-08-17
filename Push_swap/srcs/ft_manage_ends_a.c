/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_manage_ends_a.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zharzi <zharzi@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/17 22:22:51 by zharzi            #+#    #+#             */
/*   Updated: 2022/08/17 22:33:00 by zharzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pswap.h"

void	ft_manage_ends_a(t_list **astack, t_control *val)
{
	t_list	*tmp;
	int		test;

	tmp = ft_lstlast(*astack);
	test = ft_test_index(*astack, tmp);
	if (test)
		ft_move_rra(astack, val);
	if (test == -1)
		ft_move_sa(astack);
}
