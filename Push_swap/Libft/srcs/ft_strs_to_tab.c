/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strs_to_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zharzi <zharzi@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/24 16:43:13 by zharzi            #+#    #+#             */
/*   Updated: 2022/07/24 18:33:58 by zharzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

int	**ft_strs_to_tab(char **strs)
{
	int		**ret;
	int		*tab;
	int		conv;
	size_t	i;
	size_t	len;

	printf("1test int du tab %d\n", ft_check_strs_int(strs));
	i = 0;
	printf("2test int du tab %d\n", ft_check_strs_int(strs));
	len = ft_chartab_len(strs);
	printf("3test int du tab %d\n", ft_check_strs_int(strs));
	tab = (int *)malloc(sizeof(int *) * len);
	printf("4test int du tab %d\n", ft_check_strs_int(strs));
	if (tab)
	{
		printf("5test int du tab %d\n", ft_check_strs_int(strs));
		i = 0;
		printf("6test int du tab %d\n", ft_check_strs_int(strs));
		while (i < len)
		{
			conv = ft_atoi(strs[i]);
			tab[i] = conv;
			i++;
		}
		printf("7test int du tab %d\n", ft_check_strs_int(strs));
	}
	ret = &tab;
	return (ret);
}
