/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fdf_initcol.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zharzi <zharzi@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/18 14:47:48 by zharzi            #+#    #+#             */
/*   Updated: 2022/09/18 14:48:05 by zharzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

char	*ft_fdf_initcol(void)
{
	char	*color;

	color = (char *)malloc(sizeof(char) * 11);
	color = ft_memset(color, 'F', 10);
	color[0] = '0';
	color[1] = 'x';
	color[2] = '0';
	color[3] = '0';
	color[10] = '\0';
	return (color);
}
