/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hypotenuse.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zharzi <zharzi@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 16:11:20 by zharzi            #+#    #+#             */
/*   Updated: 2022/09/20 16:22:19 by zharzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_hypotenuse(int a, int b)
{
	int	c;

	a = ft_abs(a);
	b = ft_abs(b);
	c = ft_sqrt((a * a) + (b * b));
	return (c);
}
