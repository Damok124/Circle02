/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pswap.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zharzi <zharzi@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 11:57:27 by zharzi            #+#    #+#             */
/*   Updated: 2022/12/31 12:09:57 by zharzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PSWAP_H
# define PSWAP_H

# include "libft.h"
# include "ft_printf.h"

# define ASCENDING -1
# define DESCENDING 1
# define PRINT_OK 1
# define NO_PRINT 0

typedef struct s_stack {
	int				size;
	int				value;
	int				index;
	struct s_stack	*next;
}	t_stack;

/////////////////////////
//	MOVES
/////////////////////////
void	ft_move_pa(t_stack **astack, t_stack **bstack, int print);
void	ft_move_pb(t_stack **astack, t_stack **bstack, int print);
void	ft_move_ra(t_stack **astack, int print);
void	ft_move_rb(t_stack **bstack, int print);
void	ft_move_rr(t_stack **astack, t_stack **bstack, int print);
void	ft_move_rra(t_stack **astack, int print);
void	ft_move_rrb(t_stack **bstack, int print);
void	ft_move_rrr(t_stack **astack, t_stack **bstack, int print);
void	ft_move_sa(t_stack **astack, int print);
void	ft_move_sb(t_stack **bstack, int print);
void	ft_move_ss(t_stack **astack, t_stack **bstack, int print);

/////////////////////////
//	INFORMATIONS
/////////////////////////
int		ft_up_cost(t_stack **stack, int target);
int		ft_down_cost(t_stack **stack, int target);
t_stack	*ft_get_last_elem(t_stack *lst);
int		ft_stack_len(t_stack **stack);
int		ft_get_index(int value, int *ordered);

/////////////////////////
//	PARSING
/////////////////////////
t_stack	*ft_shape_stack_lst(int size);
void	ft_init_stack_a(t_stack **a, int *tab, int size);
int		ft_check_valid_char_only(char *str);
int		ft_check_valid_sign(char *str);
int		ft_check_empty_arg(char *str);
int		ft_check_overflow(char *str);
char	***ft_disjoin_args(char **argv);
int		*ft_get_parsed_tab(char **argv);
int		ft_pswap_args_check(char **argv);

/////////////////////////
//	CHECKERS
/////////////////////////
int		ft_swap_test_a(t_stack **top_a);
int		ft_test_index(t_stack *elem1, t_stack *elem2);
int		ft_check_stack_order(t_stack *stack, int order);

/////////////////////////
//	SORTERS
/////////////////////////
void	ft_sort_trio(t_stack **top_a);
void	ft_sort_quartet(t_stack **top_a, t_stack **top_b);
void	ft_sort_quintet(t_stack **top_a, t_stack **top_b);
void	ft_solve_chunks(t_stack **top_a, t_stack **top_b);
void	ft_rb_loop(t_stack **top_a, t_stack **top_b, int target, int *bonus);
void	ft_rrb_loop(t_stack **top_a, t_stack **top_b, int target, int *bonus);
void	ft_solve_all(t_stack **top_a, t_stack **top_b);
void	ft_thirds_a_in_b(t_stack **top_a, t_stack **top_b, int size, int ratio);
void	ft_chunk_a_in_b(t_stack **top_a, t_stack **top_b);
void	ft_sort(t_stack **top_a, t_stack **top_b, int *ratio);
void	ft_drain_b(t_stack **astack, t_stack **bstack);

/////////////////////////
//	VIZUALIZERS
/////////////////////////
void	ft_show_stack(t_stack **lst);
void	ft_show_it_all(t_stack **top_a, t_stack **top_b);

/////////////////////////
//	FREERS
/////////////////////////
void	ft_free_stack(t_stack **stack);

#endif
