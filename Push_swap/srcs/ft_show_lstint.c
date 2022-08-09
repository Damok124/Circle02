/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_show_lstint.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zharzi <zharzi@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/05 00:28:12 by zharzi            #+#    #+#             */
/*   Updated: 2022/08/06 23:22:41 by zharzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pswap.h"

void	ft_show_lstint(t_list **list)
{
	t_list	*tmp;
	int		data;

	if (*list)
	{
		tmp = *list;
		while (tmp)
		{
			data = *(int *)(tmp->content);
			ft_printf("[%d]", data);
			tmp = tmp->next;
			if (tmp)
				ft_printf("-");
			else
				ft_printf("\n");
		}
	}
}
