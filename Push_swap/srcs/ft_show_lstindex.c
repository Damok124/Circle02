/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_show_lstindex.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zharzi <zharzi@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/05 00:28:12 by zharzi            #+#    #+#             */
/*   Updated: 2022/08/15 14:39:51 by zharzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pswap.h"

void	ft_show_lstindex(t_list **list)
{
	t_list	*tmp;
	int		data;

	if (*list)
	{
		tmp = *list;
		while (tmp)
		{
			data = tmp->index;
			ft_printf("{%d}", data);
			tmp = tmp->next;
			if (tmp)
				ft_printf("~");
		}
	}
	ft_printf("\n");
}
