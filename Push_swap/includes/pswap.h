/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pswap.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zharzi <zharzi@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 11:57:27 by zharzi            #+#    #+#             */
/*   Updated: 2022/08/09 23:44:51 by zharzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PSWAP_H
# define PSWAP_H

# include "libft.h"
# include "ft_printf.h"

typedef struct s_control {
	int	ac;
	int	min;
	int	max;
	int	firstthird;
	int	lastthird;
}	t_control;

void	ft_move_sa(t_list **astack);
void	ft_move_sb(t_list **bstack);
void	ft_move_ss(t_list **astack, t_list **bstack);
void	ft_move_pa(t_list **astack, t_list **bstack);
void	ft_move_pb(t_list **astack, t_list **bstack);
void	ft_move_ra(t_list **astack);
void	ft_move_rb(t_list **bstack);
void	ft_move_rr(t_list **astack, t_list **bstack);
void	ft_move_rra(t_list **astack);
void	ft_move_rrb(t_list **bstack);
void	ft_move_rrr(t_list **astack, t_list **bstack);
void	ft_show_lstint(t_list **list);
int		ft_pswap_check_args(int *ac, char *full);
int		ft_pswap_intfinder(char **av);
char	*ft_pswap_join(char **av);
int		*ft_pswap_parsing(int *ac, char **av);
void	ft_ending_bstack(t_list **astack, t_list **bstack);

#endif
