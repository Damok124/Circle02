/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pswap.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zharzi <zharzi@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 11:57:27 by zharzi            #+#    #+#             */
/*   Updated: 2022/08/17 22:32:58 by zharzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PSWAP_H
# define PSWAP_H

# include "libft.h"
# include "ft_printf.h"

typedef struct s_control {
	int	ac;
	int	min;//equivalent 1
	int	max;//equivalent ac
	int	firstthird;
	int	lastthird;
	int	pop_a;
	int	pop_ea;
	int	pop_b;
	int	pop_eb;
	int	lock;
}	t_control;

/////////////////////////
//	MOVES
/////////////////////////
void		ft_move_sa(t_list **astack);
void		ft_move_sb(t_list **bstack);
void		ft_move_ss(t_list **astack, t_list **bstack);
void		ft_move_pa(t_list **astack, t_list **bstack, t_control *val);
void		ft_move_pb(t_list **astack, t_list **bstack, t_control *val);
void		ft_move_ra(t_list **astack, t_control *val);
void		ft_move_rb(t_list **bstack, t_control *val);
void		ft_move_rr(t_list **astack, t_list **bstack, t_control *val);
void		ft_move_rra(t_list **astack, t_control *val);
void		ft_move_rrb(t_list **bstack, t_control *val);
void		ft_move_rrr(t_list **astack, t_list **bstack, t_control *val);
void		ft_ra_details(t_list **astack);
void		ft_rb_details(t_list **bstack);
void		ft_rra_details(t_list **astack);
void		ft_rrb_details(t_list **bstack);
/////////////////////////
//	COMBINED MOVES
/////////////////////////
void		ft_push_to_ea(t_list **astack, t_control *val);
void		ft_push_to_b(t_list **astack, t_list **bstack, t_control *val);
void		ft_push_to_eb(t_list **astack, t_list **bstack, t_control *val);
void		ft_get_from_ea(t_list **astack, t_control *val);
void		ft_get_from_b(t_list **astack, t_list **bstack, t_control *val);
void		ft_get_from_eb(t_list **astack, t_list **bstack, t_control *val);
void		ft_ending_bstack(t_list **astack, t_list **bstack, t_control *val);
void		ft_pswap_distri(t_list **astack, t_list **bstack, t_control *val);
void		ft_manage_ends_a(t_list **astack, t_control *val);
/////////////////////////
//	CONTROL
/////////////////////////
int			ft_pswap_check_args(int *ac, char *full);
int			ft_pswap_intfinder(char **av);
int			ft_pswap_final(t_list **astack, t_list **bstack, t_control *val);
int			ft_test_index(t_list *tmp1, t_list *tmp2);
int			ft_swap_test(t_list **astack, t_list **bstack, t_control *val);
void		ft_swap_top_test(t_list **astack, t_list **bstack, t_control *val);
int			ft_check_order_a(t_list	*astack, t_control *val);
int			ft_check_order_ae(t_list *astack, t_control *val);
int			ft_check_order_b(t_list	**bstack, t_control *val);
int			ft_check_order_eb(t_list **bstack, t_control *val);
int			ft_pswap_order(t_list **stack, int pop);
int			ft_stack_check_order(t_list *stack, int pop, int order);
int			ft_lock_elem(t_list **astack, t_control	**val);
/////////////////////////
//	DATAS
/////////////////////////
char		*ft_pswap_join(char **av);
int			*ft_pswap_parsing(int *ac, char **av);
t_control	ft_fill_controlval(int ac);
t_list		*ft_first_estack(t_list **stack, int pop);
/////////////////////////
//	VIEW
/////////////////////////
void		ft_show_lstint(t_list **list, int pop);
void		ft_show_stacks(t_list **astack, t_list **bstack, t_control *val);
void		ft_show_values(t_control val);
void		ft_show_lstindex(t_list **list);
void		ft_pswap_view(t_list **astack, t_list **bstack, t_control *val);

#endif
