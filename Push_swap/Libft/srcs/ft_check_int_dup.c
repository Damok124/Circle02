/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_int_dup.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zharzi <zharzi@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/24 11:36:05 by zharzi            #+#    #+#             */
/*   Updated: 2022/07/24 13:57:07 by zharzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h" /////a mettre dans la libft

int	ft_check_int_dup(int **tab)
{
	size_t	i;
	size_t	j;
	size_t	len;

	i = 0;
	j = i + 1;
	len = ft_inttab_len(tab);
	while (len > 0 && j < len)
	{
		while (j < len)
		{
			if (tab[i] == tab[j])
				return (0);
			j++;
		}
		i++;
		j = i + 1;
	}
	return (1);
}
