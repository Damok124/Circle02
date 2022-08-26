/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_show_lstint.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zharzi <zharzi@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/05 00:28:12 by zharzi            #+#    #+#             */
/*   Updated: 2022/08/20 21:23:23 by zharzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pswap.h"

void	ft_show_lstint(t_list **list, int pop)
{
	t_list	*tmp;
	int		data;

	if (*list)
	{
		tmp = *list;
		while (tmp && pop)
		{
			data = *(int *)(tmp->content);
			ft_printf("[%d]", data);
			tmp = tmp->next;
			pop--;
			if (tmp && pop)
				ft_printf("~");
		}
	}
}
