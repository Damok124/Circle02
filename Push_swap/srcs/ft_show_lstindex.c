/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_show_lstindex.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zharzi <zharzi@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/05 00:28:12 by zharzi            #+#    #+#             */
/*   Updated: 2022/08/20 21:23:35 by zharzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pswap.h"

void	ft_show_lstindex(t_list **list, int pop)
{
	t_list	*tmp;

	if (*list)
	{
		tmp = *list;
		while (tmp && pop)
		{
			ft_printf("[{%d}]", tmp->index);
			tmp = tmp->next;
			pop--;
			if (tmp && pop)
				ft_printf("~");
		}
	}
}
