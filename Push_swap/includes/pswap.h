/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pswap.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zharzi <zharzi@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 11:57:27 by zharzi            #+#    #+#             */
/*   Updated: 2022/07/24 13:14:40 by zharzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PSWAP_H
# define PSWAP_H

# include <unistd.h>
# include "ft_printf.h"
# include "libft.h"

void	ft_move_sa(char **a, char **b);
void	ft_move_sb(char **a, char **b);
void	ft_move_ss(char **a, char **b);
void	ft_move_pa(char **a, char **b);
void	ft_move_pb(char **a, char **b);
void	ft_move_ra(char **a, char **b);
void	ft_move_rb(char **a, char **b);
void	ft_move_rr(char **a, char **b);
void	ft_move_rra(char **a, char **b);
void	ft_move_rrb(char **a, char **b);
void	ft_move_rrr(char **a, char **b);

#endif
