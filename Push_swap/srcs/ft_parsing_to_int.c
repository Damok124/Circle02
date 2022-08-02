/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing_to_int.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zharzi <zharzi@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 22:34:37 by zharzi            #+#    #+#             */
/*   Updated: 2022/08/02 20:28:38 by zharzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pswap.h"
/*
int	*ft_parsing_to_int(char **av)
{
	char	*concat;
	char	*tmp;
	char	**strs;
	int		*tab;
	int		i;

	i = -1;
	concat = (char *)malloc(sizeof(char *));
	while (av[++i])
	{
		tmp = concat;
		concat = ft_strjoin(concat, av[i]);
		ft_true_free(tmp);
		tmp = concat;
		concat = ft_strjoin(concat, " ");
		ft_true_free(tmp);
	}
	strs = ft_split(concat, ' ');
	tab = ft_strs_to_tab(av);
	i = -1;
	while (strs[++i])
		ft_true_free(strs[i]);
	ft_true_free(strs);
	ft_true_free(concat);
	return (tab);
}
*/
/*
int	*ft_parsing_to_int(char **av)
{
	char	*concat;
	void	**ptr;
	int		*tab;
	int		i;
	int		j;

	i = -1;
	j = -1;
	concat = (char *)malloc(sizeof(char) * 2);
	if (!concat)
		return (NULL);
	concat = " \0";
	*ptr = NULL;
	while (av[++i])
	{
		ptr[++j] = &concat;
		concat = ft_strjoin(concat, av[i]);
		ptr[++j] = &concat;
		concat = ft_strjoin(concat, " ");
	}
	while (j >= 0)
		ft_true_free(ptr[j--]);
	av = ft_split(concat, ' ');
	tab = ft_strs_to_tab(av);
	ft_true_free(av);
	return (tab);
}
*/
