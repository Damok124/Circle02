/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fdf_buffertrim.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zharzi <zharzi@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/18 18:10:11 by zharzi            #+#    #+#             */
/*   Updated: 2022/09/18 18:10:38 by zharzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

char	*ft_fdf_buffertrim(char *buffer)
{
	char	*tmp;

	tmp = ft_strtrim(buffer, "\n");
	ft_true_free(&buffer);
	buffer = ft_strtrim(tmp, " ");
	ft_true_free(&tmp);
	return (buffer);
}
