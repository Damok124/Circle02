/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strs_to_intlst.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zharzi <zharzi@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/02 11:11:42 by zharzi            #+#    #+#             */
/*   Updated: 2022/07/29 01:54:00 by zharzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pswap.h"

t_elem	*ft_strs_to_intlst(int ac, char **av)
{
	t_elem	*current;
	t_elem	*first;
	int		i;

	i = -1;
	first = NULL;
	while (++i < ac)
	{
		current = ft_new_elem(ft_atoi(av[i]));
		ft_lstadd_down(&first, current);
	}
	return (first);
}
