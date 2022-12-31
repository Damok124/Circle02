/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_parsed_tab.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zharzi <zharzi@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/31 11:58:22 by zharzi            #+#    #+#             */
/*   Updated: 2022/12/31 12:50:50 by zharzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pswap.h"

int	*ft_get_parsed_tab(char **argv)
{
	char	***splited;
	char	**aligned;
	int		*tab;
	int		*ordered;

	splited = ft_disjoin_args(argv);
	aligned = ft_strs_triple_into_double(splited);
	tab = ft_strs_to_tab(ft_strslen(aligned), aligned);
	ordered = ft_sort_int_tab(tab, ft_strslen(aligned));
	if (!ft_check_dup_int(ft_strslen(aligned), ordered))
		ft_true_free((void **)&tab);
	ft_full_free((void **)aligned);
	ft_true_free((void **)&ordered);
	return (tab);
}
