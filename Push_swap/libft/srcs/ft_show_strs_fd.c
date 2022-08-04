/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_show_strs_fd.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zharzi <zharzi@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 00:25:40 by zharzi            #+#    #+#             */
/*   Updated: 2022/08/04 00:49:01 by zharzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_show_strs_fd(char **strs, int fd)
{
	t_count	c;

	c.i = 0;
	while (strs && strs[c.i])
	{
		ft_putstr_fd(strs[c.i], fd);
		c.i++;
	}
}
