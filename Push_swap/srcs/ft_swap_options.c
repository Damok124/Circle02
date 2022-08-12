/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap_options.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zharzi <zharzi@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/12 11:28:40 by zharzi            #+#    #+#             */
/*   Updated: 2022/08/12 14:36:02 by zharzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pswap.h"

void	ft_swap_options(t_list **astack, t_list **bstack, t_control *val)
{
	if ((*astack && (*astack)->next) || (*bstack && (*bstack)->next))
	{

		//ft_swap_test_top(astack, bstack);
		if (*astack != ft_lstlast(*astack) && *bstack != ft_lstlast(*bstack))
		{
			ft_printf("SWAPPP OPTIONS");
			ft_swap_test_edge(astack, bstack, val);
		}
	}
}
