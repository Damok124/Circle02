/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_show_stacks.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zharzi <zharzi@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/11 11:21:36 by zharzi            #+#    #+#             */
/*   Updated: 2022/08/11 11:22:04 by zharzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pswap.h"

void	ft_show_stacks(t_list **astack, t_list **bstack)
{
	ft_printf("astack : ");
	ft_show_lstint(astack);
	ft_printf("bstack : ");
	ft_show_lstint(bstack);
}
