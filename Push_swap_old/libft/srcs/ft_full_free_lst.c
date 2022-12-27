/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_full_free_lst.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zharzi <zharzi@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/05 00:28:23 by zharzi            #+#    #+#             */
/*   Updated: 2022/08/26 16:41:51 by zharzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_full_free_lst(t_list **list)
{
	t_list	*tmp;

	tmp = NULL;
	while (*list)
	{
		(*list)->content = NULL;
		tmp = (*list)->next;
		(*list)->next = NULL;
		ft_true_free(*list);
		*list = tmp;
	}
}
