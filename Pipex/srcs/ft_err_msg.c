/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_err_msg.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zharzi <zharzi@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 15:19:42 by zharzi            #+#    #+#             */
/*   Updated: 2022/10/20 15:29:12 by zharzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_err_msg(char *filename, char *str)
{
	write(2, "bash: ", ft_strlen("bash: "));
	write(2, filename, ft_strlen(filename));
	write(2, str, ft_strlen(str));
}
