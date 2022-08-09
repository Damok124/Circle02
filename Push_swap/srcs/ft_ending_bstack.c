/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ending_bstack.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zharzi <zharzi@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/07 17:29:50 by zharzi            #+#    #+#             */
/*   Updated: 2022/08/07 17:51:04 by zharzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pswap.h"

void	ft_ending_bstack(t_list **astack, t_list **bstack)
{
	while (*bstack)
		ft_move_pa(astack, bstack);
}
