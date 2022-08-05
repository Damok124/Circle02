/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_full_free_lst.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zharzi <zharzi@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/05 00:28:23 by zharzi            #+#    #+#             */
/*   Updated: 2022/08/05 00:30:09 by zharzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_full_free_lst(t_list **list)
{
	t_list	*tmp;
	t_list	*buf;

	tmp = *list;
	ft_memset_lst(list, NULL);
	while (tmp)
	{
		buf = tmp->next;
		ft_true_free(tmp);
		tmp = buf;
	}
	if (list)
		ft_true_free(list);
}
