/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pswap_parsing.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zharzi <zharzi@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 00:02:26 by zharzi            #+#    #+#             */
/*   Updated: 2022/08/26 16:38:26 by zharzi           ###   ########.fr       */
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
	while (++i < (ssize_t)(*ac - 1))
	{
		if (av[i][0] == '\0')
			return (NULL);
	}
	full = ft_pswap_join(av);
	if (!full || !ft_pswap_check_args(ac, full))
		return (NULL);
	finalcut = ft_split(full, ' ');
	tab = ft_strs_to_tab(*ac, finalcut);
	ft_true_free(full);
	ft_full_free((void **)finalcut);
	return (tab);
}
