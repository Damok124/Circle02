/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_show_tab_fd.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zharzi <zharzi@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 00:25:42 by zharzi            #+#    #+#             */
/*   Updated: 2022/08/04 00:47:57 by zharzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_show_tab_fd(int len, int *tab, int fd)
{
	t_count	c;

	c.i = 0;
	while (tab && c.i < len)
	{
		ft_putnbr_fd(tab[c.i], fd);
		c.i++;
	}
}
