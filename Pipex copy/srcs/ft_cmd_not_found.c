/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cmd_not_found.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zharzi <zharzi@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 21:42:36 by zharzi            #+#    #+#             */
/*   Updated: 2022/10/20 01:21:38 by zharzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_cmd_not_found(char *str)
{
	write(2, "Command '", ft_strlen("Command '"));
	write(2, str, ft_strlen(str));
	write(2, "' not found.\n", ft_strlen("' not found.\n"));
}
