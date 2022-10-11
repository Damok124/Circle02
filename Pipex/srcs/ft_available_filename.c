/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_available_filename.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zharzi <zharzi@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 18:28:57 by zharzi            #+#    #+#             */
/*   Updated: 2022/10/11 18:29:16 by zharzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*ft_available_filename(char *basename)
{
	int		pattern;
	char	*buildedname;
	int		len;

	len = ft_strlen(basename);
	pattern = ft_pattern_count(basename);
	buildedname = ft_get_tmpname(basename, pattern, len);
	if (buildedname)
		return (buildedname);
	return (NULL);
}
