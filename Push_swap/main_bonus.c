/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zharzi <zharzi@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 00:17:59 by zharzi            #+#    #+#             */
/*   Updated: 2022/12/30 23:52:30 by zharzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pswap.h"

int	main(int ac, char **argv)
{
	ft_printf("%d\n", ac);
	ft_print_strs(argv);
	return (0);
}

/*
void	ft_move_rrr(t_stack **astack, t_stack **bstack, int print)
{
	if (*astack && (*astack)->next && *bstack && (*bstack)->next)
	{
		ft_move_rra(astack, 0);
		ft_move_rrb(bstack, 0);
		// tmp2 = *astack;
		// while (tmp2 && tmp2->next)
		// {
		// 	tmp1 = tmp2;
		// 	tmp2 = tmp2->next;
		// }
		// tmp1->next = NULL;
		// tmp2->next = *astack;
		// *astack = tmp2;
		// tmp2 = *bstack;
		// while (tmp2 && tmp2->next)
		// {
		// 	tmp1 = tmp2;
		// 	tmp2 = tmp2->next;
		// }
		// tmp1->next = NULL;
		// tmp2->next = *bstack;
		// *bstack = tmp2;
		if (print)
			ft_printf("rrr\n");
	}
}
*/
