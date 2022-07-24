/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_show_tab.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zharzi <zharzi@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/25 00:15:20 by zharzi            #+#    #+#             */
/*   Updated: 2022/07/25 00:23:49 by zharzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_show_tab(t_list **par, int fd)
{
	int	i;

	i = 0;
	while (par[i]->content)
	{
		ft_putnbr_fd(*(int *)par[i]->content, fd);
		write(1, "\n", 1);
		i++;
	}
}
