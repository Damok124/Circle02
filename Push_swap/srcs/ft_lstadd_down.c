/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_down.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zharzi <zharzi@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 18:02:31 by zharzi            #+#    #+#             */
/*   Updated: 2022/08/04 03:26:48 by zharzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pswap.h"

void	ft_lstadd_down(t_elem **lst, t_elem *newl)
{
	t_elem	*tmp;
	int		i;

	i = 0;
	tmp = *lst;
	if (tmp)
	{
		while (tmp->down != NULL)
		{
			ft_printf("test%d", i++);
			tmp = tmp->down;
		}
		tmp->down = newl;
	}
	else
		*lst = newl;
}
