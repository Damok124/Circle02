/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tab_to_lst.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zharzi <zharzi@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/05 00:27:53 by zharzi            #+#    #+#             */
/*   Updated: 2022/08/07 23:26:02 by zharzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_tab_to_lst(int ac, int *tab)
{
	t_list	*list;
	int		i;

	i = -1;
	list = NULL;
	if (tab && ac > 0)
		while (++i < ac)
			ft_lstadd_back(&list, ft_lstnew(&tab[i]));
	return (list);
}
