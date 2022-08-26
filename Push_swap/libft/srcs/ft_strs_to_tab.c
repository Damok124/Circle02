/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strs_to_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zharzi <zharzi@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 00:25:33 by zharzi            #+#    #+#             */
/*   Updated: 2022/08/26 16:38:33 by zharzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	*ft_strs_to_tab(int len, char **strs)
{
	t_count	c;
	int		*tab;
	int		tester;

	c.i = -1;
	tester = 1;
	tab = (int *)malloc(sizeof(int) * len);
	if (!tab)
		return (NULL);
	ft_memset(tab, 0, sizeof(int) * len);
	while (tester > 0 && strs && strs[++c.i])
		tab[c.i] = ft_atoi_safe(strs[c.i], &tester);
	if (tester == 0)
	{
		if (tab)
			ft_true_free(tab);
		return (NULL);
	}
	return (tab);
}
