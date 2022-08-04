/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_show_contents.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zharzi <zharzi@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/25 00:15:20 by zharzi            #+#    #+#             */
/*   Updated: 2022/08/04 00:42:29 by zharzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_show_contents(t_list **par, int fd)
{
	int	i;

	i = 0;
	while (par[i]->content)
	{
		ft_putnbr_fd(*(int *)par[i]->content, fd);
		write(fd, "\n", 1);
		i++;
	}
}
