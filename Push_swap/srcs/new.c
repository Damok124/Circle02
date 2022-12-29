/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move_pa.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zharzi <zharzi@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/24 04:57:16 by zharzi            #+#    #+#             */
/*   Updated: 2022/08/26 16:41:56 by zharzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pswap.h"

void	ft_move_pa(t_list **astack, t_list **bstack, t_control *val)
{
	t_list	*tmp1;

	if (*bstack)
	{
		tmp1 = *bstack;
		*bstack = (*bstack)->next;
		tmp1->next = *astack;
		*astack = tmp1;
		if (val->pop_b)
			val->pop_b--;
		else
			val->pop_eb--;
		val->pop_a++;
		val->total++;
		ft_printf("pa\n");
	}
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move_pb.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zharzi <zharzi@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/24 04:57:31 by zharzi            #+#    #+#             */
/*   Updated: 2022/08/26 16:41:57 by zharzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pswap.h"

void	ft_move_pb(t_list **astack, t_list **bstack, t_control *val)
{
	t_list	*tmp1;

	if (*astack)
	{
		tmp1 = *astack;
		*astack = (*astack)->next;
		tmp1->next = *bstack;
		*bstack = tmp1;
		if (val->pop_a)
			val->pop_a--;
		else
			val->pop_ea--;
		val->pop_b++;
		val->total++;
		ft_printf("pb\n");
	}
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move_ra.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zharzi <zharzi@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/24 04:57:40 by zharzi            #+#    #+#             */
/*   Updated: 2022/08/26 16:42:23 by zharzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pswap.h"

void	ft_ra_details(t_list **astack)
{
	t_list	*tmp1;
	t_list	*tmp2;

	if (*astack && (*astack)->next)
	{
		tmp2 = *astack;
		*astack = (*astack)->next;
		tmp2->next = NULL;
		tmp1 = *astack;
		while (tmp1 && tmp1->next)
			tmp1 = tmp1->next;
		tmp1->next = tmp2;
	}
}

void	ft_move_ra(t_list **astack, t_control *val)
{
	if (*astack && (*astack)->next)
		ft_ra_details(astack);
	if (val->pop_a)
	{
		val->pop_a--;
		val->pop_ea++;
		val->total++;
	}
	ft_printf("ra\n");
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move_rb.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zharzi <zharzi@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/24 04:57:54 by zharzi            #+#    #+#             */
/*   Updated: 2022/08/26 16:42:01 by zharzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pswap.h"

void	ft_rb_details(t_list **bstack)
{
	t_list	*tmp1;
	t_list	*tmp2;

	if (*bstack && (*bstack)->next)
	{
		tmp2 = *bstack;
		*bstack = (*bstack)->next;
		tmp2->next = NULL;
		tmp1 = *bstack;
		while (tmp1 && tmp1->next)
			tmp1 = tmp1->next;
		tmp1->next = tmp2;
	}
}

void	ft_move_rb(t_list **bstack, t_control *val)
{
	if (*bstack && (*bstack)->next)
		ft_rb_details(bstack);
	if (val->pop_b)
	{
		val->pop_b--;
		val->pop_eb++;
		val->total++;
	}
	ft_printf("rb\n");
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move_rra.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zharzi <zharzi@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/24 04:58:13 by zharzi            #+#    #+#             */
/*   Updated: 2022/08/22 16:11:11 by zharzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pswap.h"

void	ft_rra_details(t_list **astack)
{
	t_list	*tmp1;
	t_list	*tmp2;

	if (*astack && (*astack)->next)
	{
		tmp2 = *astack;
		while (tmp2 && tmp2->next)
		{
			tmp1 = tmp2;
			tmp2 = tmp2->next;
		}
		tmp1->next = NULL;
		tmp2->next = *astack;
		*astack = tmp2;
	}
}

void	ft_move_rra(t_list **astack, t_control *val)
{
	if (*astack && (*astack)->next)
	{
		ft_rra_details(astack);
		if (val->pop_ea)
		{
			val->pop_a++;
			val->pop_ea--;
		}
		val->total++;
		ft_printf("rra\n");
	}
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move_rrb.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zharzi <zharzi@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/24 04:59:58 by zharzi            #+#    #+#             */
/*   Updated: 2022/08/26 16:42:08 by zharzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pswap.h"

void	ft_rrb_details(t_list **bstack)
{
	t_list	*tmp1;
	t_list	*tmp2;

	if (*bstack && (*bstack)->next)
	{
		tmp2 = *bstack;
		while (tmp2 && tmp2->next)
		{
			tmp1 = tmp2;
			tmp2 = tmp2->next;
		}
		tmp1->next = NULL;
		tmp2->next = *bstack;
		*bstack = tmp2;
	}
}

void	ft_move_rrb(t_list **bstack, t_control *val)
{
	if (*bstack && (*bstack)->next)
	{
		ft_rrb_details(bstack);
		if (val->pop_eb)
		{
			val->pop_b++;
			val->pop_eb--;
		}
		val->total++;
		ft_printf("rrb\n");
	}
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move_rr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zharzi <zharzi@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/24 04:58:04 by zharzi            #+#    #+#             */
/*   Updated: 2022/08/22 15:55:26 by zharzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pswap.h"

void	ft_move_rr(t_list **astack, t_list **bstack, t_control *val)
{
	if (*astack && (*astack)->next && *bstack && (*bstack)->next)
	{
		ft_ra_details(astack);
		ft_rb_details(bstack);
		if (val->pop_a)
		{
			val->pop_a--;
			val->pop_ea++;
		}
		if (val->pop_b)
		{
			val->pop_b--;
			val->pop_eb++;
			val->total++;
		}
		ft_printf("rr\n");
	}
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move_rrr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zharzi <zharzi@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/24 05:00:08 by zharzi            #+#    #+#             */
/*   Updated: 2022/08/22 16:11:22 by zharzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pswap.h"

void	ft_move_rrr(t_list **astack, t_list **bstack, t_control *val)
{
	if (*astack && (*astack)->next && *bstack && (*bstack)->next)
	{
		ft_rra_details(astack);
		ft_rrb_details(bstack);
		if (val->pop_ea)
		{
			val->pop_a++;
			val->pop_ea--;
		}
		if (val->pop_eb)
		{
			val->pop_b++;
			val->pop_eb--;
		}
		val->total++;
		ft_printf("rrr\n");
	}
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move_sa.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zharzi <zharzi@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/24 04:49:14 by zharzi            #+#    #+#             */
/*   Updated: 2022/08/26 16:42:09 by zharzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pswap.h"

void	ft_move_sa(t_list **astack, t_control *val)
{
	t_list	*elem3;
	t_list	*elem2;

	if (*astack && (*astack)->next)
	{
		elem3 = (*astack)->next;
		elem2 = elem3;
		elem3 = elem3->next;
		elem2->next = *astack;
		(*astack)->next = elem3;
		*astack = elem2;
		val->total++;
		ft_printf("sa\n");
	}
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_moves_backward.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zharzi <zharzi@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/11 11:14:00 by zharzi            #+#    #+#             */
/*   Updated: 2022/08/26 17:54:27 by zharzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pswap.h"

void	ft_get_from_ea(t_list **astack, t_control *val)
{
	ft_move_rra(astack, val);
}

void	ft_get_from_b(t_list **astack, t_list **bstack, t_control *val)
{
	ft_move_pa(astack, bstack, val);
}

void	ft_get_from_eb(t_list **astack, t_list **bstack, t_control *val)
{
	ft_move_rrb(bstack, val);
	ft_move_pa(astack, bstack, val);
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move_sb.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zharzi <zharzi@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/24 05:00:25 by zharzi            #+#    #+#             */
/*   Updated: 2022/08/22 15:56:08 by zharzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pswap.h"

void	ft_move_sb(t_list **bstack, t_control *val)
{
	t_list	*elem3;
	t_list	*elem2;

	if (*bstack && (*bstack)->next)
	{
		elem3 = (*bstack)->next;
		elem2 = elem3;
		elem3 = elem3->next;
		elem2->next = *bstack;
		(*bstack)->next = elem3;
		*bstack = elem2;
		val->total++;
		ft_printf("sb\n");
	}
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_moves_forward.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zharzi <zharzi@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/11 11:09:03 by zharzi            #+#    #+#             */
/*   Updated: 2022/08/26 17:53:44 by zharzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pswap.h"

void	ft_push_to_ea(t_list **astack, t_control *val)
{
	ft_move_ra(astack, val);
}

void	ft_push_to_b(t_list **astack, t_list **bstack, t_control *val)
{
	ft_move_pb(astack, bstack, val);
}

void	ft_push_to_eb(t_list **astack, t_list **bstack, t_control *val)
{
	ft_move_pb(astack, bstack, val);
	if (*bstack && (*bstack)->next && \
	(*bstack)->index - 1 != (*bstack)->next->index)
		ft_move_rb(bstack, val);
	else
	{
		val->pop_b--;
		val->pop_eb++;
	}
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move_ss.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zharzi <zharzi@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/24 05:00:32 by zharzi            #+#    #+#             */
/*   Updated: 2022/08/22 15:56:16 by zharzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pswap.h"

void	ft_move_ss(t_list **astack, t_list **bstack, t_control *val)
{
	t_list	*elem3;
	t_list	*elem2;

	if (*astack && (*astack)->next && *bstack && (*bstack)->next)
	{
		elem3 = (*astack)->next;
		elem2 = elem3;
		elem3 = elem3->next;
		elem2->next = *astack;
		(*astack)->next = elem3;
		*astack = elem2;
		elem3 = (*bstack)->next;
		elem2 = elem3;
		elem3 = elem3->next;
		elem2->next = *bstack;
		(*bstack)->next = elem3;
		*bstack = elem2;
		val->total++;
		ft_printf("ss\n");
	}
}
