/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pswap.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zharzi <zharzi@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 11:57:27 by zharzi            #+#    #+#             */
/*   Updated: 2022/08/04 03:27:08 by zharzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PSWAP_H
# define PSWAP_H

# include "libft.h"
# include "ft_printf.h"

typedef struct s_elem {
	int		data;
	void	*up;
	void	*down;
}			t_elem;

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
int		ft_pswap_check_args(int *ac, char *full);
int		ft_pswap_intfinder(char **av);
char	*ft_pswap_join(char **av);
int		*ft_pswap_parsing(int *ac, char **av);

t_elem	*ft_new_elem(int n);
void	ft_lstadd_down(t_elem **lst, t_elem *newl);

#endif
