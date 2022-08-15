/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pswap_distri.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zharzi <zharzi@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 14:20:16 by zharzi            #+#    #+#             */
/*   Updated: 2022/08/15 18:12:29 by zharzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pswap.h"

void	ft_pswap_distri(t_list **astack, t_list **bstack, t_control *val)
{
	if ((*astack)->index > val->lastthird)
		ft_push_to_ea(astack, val);
	else if ((*astack)->index < val->firstthird)
		ft_push_to_eb(astack, bstack, val);
	else
		ft_push_to_b(astack, bstack, val);
}//doper la fonction : doit push en boucle tant que les elements se suivent bien
