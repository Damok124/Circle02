/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tab_to_lst.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zharzi <zharzi@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/05 00:27:53 by zharzi            #+#    #+#             */
/*   Updated: 2022/08/05 00:28:49 by zharzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	**ft_tab_to_lst(int ac, int *tab)
{
	t_list	**list;
	t_count	c;

	c.i = 0;
	list = (t_list **)malloc(sizeof(t_list *));
	if (tab && tab[0])
		*list = ft_lstnew(&tab[0]);
	if (!list)
		return (NULL);
	if (tab)
		while (++c.i < ac)
			ft_lstadd_back(list, ft_lstnew(&tab[c.i]));
	return (list);
}
