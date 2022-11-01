/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_double_fullfree.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zharzi <zharzi@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 19:42:09 by zharzi            #+#    #+#             */
/*   Updated: 2022/11/01 19:42:11 by zharzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_double_fullfree(char **strs1, char **strs2)
{
	ft_full_free((void **)strs1);
	ft_full_free((void **)strs2);
}
