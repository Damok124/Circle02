/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_true_free_tab.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zharzi <zharzi@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/24 17:42:37 by zharzi            #+#    #+#             */
/*   Updated: 2022/07/24 18:14:46 by zharzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_true_free_tab(char **strs)
{
	int	i;

	i = 0;
	while (strs[i])
	{
		ft_true_free(strs[i]);
		i++;
	}
	ft_true_free(strs);
}
