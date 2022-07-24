/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strs_to_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zharzi <zharzi@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/02 11:11:42 by zharzi            #+#    #+#             */
/*   Updated: 2022/07/24 23:07:26 by zharzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	**ft_strs_to_tab(int ac, char **av)
{
	int		i;
	t_list	**tab;

	i = -1;
	tab = (t_list **)malloc(sizeof(t_list *) * ac);
	if (!tab)
		return (NULL);
	while (++i < ac)
		tab[i] = ft_lstnew(av[i]);
	return (tab);
}
