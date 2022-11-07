/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cmd_not_found_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zharzi <zharzi@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 23:59:46 by zharzi            #+#    #+#             */
/*   Updated: 2022/11/08 00:16:23 by zharzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	ft_cmd_not_found(char *str)
{
	write(2, "Command '", ft_strlen("Command '"));
	write(2, str, ft_strlen(str));
	write(2, "' not found.\n", ft_strlen("' not found.\n"));
}
