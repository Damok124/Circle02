/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_disjoin_args.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zharzi <zharzi@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/31 11:58:22 by zharzi            #+#    #+#             */
/*   Updated: 2022/12/31 12:50:31 by zharzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pswap.h"

char	***ft_disjoin_args(char **argv)
{
	char	***splited;
	int		i;

	i = 0;
	splited = NULL;
	splited = (char ***)malloc(sizeof(char **) * (ft_strslen(argv) + 1));
	if (!splited)
		return (NULL);
	splited[ft_strslen(argv)] = NULL;
	while (argv[i])
	{
		splited[i] = ft_split_set(argv[i], " \b\t\n\v\f\r");
		i++;
	}
	return (splited);
}
