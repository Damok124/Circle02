/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pswap_parsing.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zharzi <zharzi@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 00:02:26 by zharzi            #+#    #+#             */
/*   Updated: 2022/08/30 13:05:15 by zharzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pswap.h"

int	*ft_pswap_parsing(int *ac, char **av)
{
	int		i;
	char	*full;
	char	**finalcut;
	int		*tab;

	i = -1;
	tab = NULL;
	if (*ac < 2 || !av || !ft_pswap_intfinder(av))
		return (NULL);
	while (++i < (*ac - 1))
	{
		if (av[i][0] == '\0')
			return (NULL);
	}
	full = ft_pswap_join(av);
	if (!ft_pswap_check_args(ac, full))
		return (ft_true_free(full), NULL);
	finalcut = ft_split(full, ' ');
	tab = ft_strs_to_tab(*ac, finalcut);
	ft_true_free(full);
	ft_full_free((void **)finalcut);
	return (tab);
}
