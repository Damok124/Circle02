# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: zharzi <zharzi@student.42angouleme.fr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/06 17:12:24 by zharzi            #+#    #+#              #
#    Updated: 2023/01/07 21:24:50 by zharzi           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libpswap.a

BINARY = push_swap

BINARY_BONUS = checker

SRCSDIR = ./srcs/

SRCSBONUSDIR = ./srcs_bonus/

SRCS = \
${SRCSDIR}ft_move_pa.c \
${SRCSDIR}ft_move_pb.c \
${SRCSDIR}ft_move_ra.c \
${SRCSDIR}ft_move_rb.c \
${SRCSDIR}ft_move_rr.c \
${SRCSDIR}ft_move_rra.c \
${SRCSDIR}ft_move_rrb.c \
${SRCSDIR}ft_move_rrr.c \
${SRCSDIR}ft_move_sa.c \
${SRCSDIR}ft_move_sb.c \
${SRCSDIR}ft_move_ss.c \
${SRCSDIR}ft_up_cost.c \
${SRCSDIR}ft_down_cost.c \
${SRCSDIR}ft_get_last_elem.c \
${SRCSDIR}ft_stack_len.c \
${SRCSDIR}ft_get_index.c \
${SRCSDIR}ft_shape_stack_lst.c \
${SRCSDIR}ft_init_stack_a.c \
${SRCSDIR}ft_check_valid_char_only.c \
${SRCSDIR}ft_check_valid_sign.c \
${SRCSDIR}ft_check_empty_arg.c \
${SRCSDIR}ft_check_overflow.c \
${SRCSDIR}ft_disjoin_args.c \
${SRCSDIR}ft_get_parsed_tab.c \
${SRCSDIR}ft_pswap_args_check.c \
${SRCSDIR}ft_swap_test_a.c \
${SRCSDIR}ft_test_index.c \
${SRCSDIR}ft_check_stack_order.c \
${SRCSDIR}ft_sort_trio.c \
${SRCSDIR}ft_sort_quartet.c \
${SRCSDIR}ft_sort_quintet.c \
${SRCSDIR}ft_solve_chunks.c \
${SRCSDIR}ft_rb_loop.c \
${SRCSDIR}ft_rrb_loop.c \
${SRCSDIR}ft_solve_all.c \
${SRCSDIR}ft_thirds_a_in_b.c \
${SRCSDIR}ft_chunk_a_in_b.c \
${SRCSDIR}ft_sort.c \
${SRCSDIR}ft_drain_b.c \
${SRCSDIR}ft_show_stack.c \
${SRCSDIR}ft_show_it_all.c \
${SRCSDIR}ft_free_stack.c

SRCSBONUS = \
${SRCSBONUSDIR}ft_checker.c \
${SRCSBONUSDIR}ft_move_pa.c \
${SRCSBONUSDIR}ft_move_pb.c \
${SRCSBONUSDIR}ft_move_ra.c \
${SRCSBONUSDIR}ft_move_rb.c \
${SRCSBONUSDIR}ft_move_rr.c \
${SRCSBONUSDIR}ft_move_rra.c \
${SRCSBONUSDIR}ft_move_rrb.c \
${SRCSBONUSDIR}ft_move_rrr.c \
${SRCSBONUSDIR}ft_move_sa.c \
${SRCSBONUSDIR}ft_move_sb.c \
${SRCSBONUSDIR}ft_move_ss.c \
${SRCSBONUSDIR}ft_get_index.c \
${SRCSBONUSDIR}ft_shape_stack_lst.c \
${SRCSBONUSDIR}ft_init_stack_a.c \
${SRCSBONUSDIR}ft_check_valid_char_only.c \
${SRCSBONUSDIR}ft_check_valid_sign.c \
${SRCSBONUSDIR}ft_check_empty_arg.c \
${SRCSBONUSDIR}ft_check_overflow.c \
${SRCSBONUSDIR}ft_disjoin_args.c \
${SRCSBONUSDIR}ft_get_parsed_tab.c \
${SRCSBONUSDIR}ft_pswap_args_check.c \
${SRCSBONUSDIR}ft_show_stack.c \
${SRCSBONUSDIR}ft_show_it_all.c \
${SRCSBONUSDIR}ft_free_stack.c

HEADERDIR = includes/

HEADER = pswap.h

HEADERBONUS = pswap_bonus.h

OBJ = $(SRCS:.c=.o)

OBJBONUS = $(SRCSBONUS:.c=.o)

CC = clang

FLAGS = -Wall -Wextra -Werror -g3

IFLAG = -I$(HEADERDIR) -Ift_printf/includes/ -Ilibft/includes/

all : ${NAME} libft_printf.a libft.a ${BINARY}

${BINARY} :
	$(CC) $(FLAGS) main.c $(IFLAG) -L. -lpswap -L./libft -lft -L./ft_printf \
	-lft_printf -o $(BINARY)

bonus : libpswap_bonus.a libft_printf.a libft.a ${BINARY_BONUS}

${BINARY_BONUS} :
	$(CC) $(FLAGS) main_bonus.c $(IFLAG) -L. -lpswap_bonus -L./libft -lft \
	-L./ft_printf -lft_printf -o $(BINARY_BONUS)

%.o : %.c
	$(CC) $(FLAGS) $(IFLAG) -o $@ -c $^

${NAME} : $(OBJ) $(HEADERDIR)$(HEADER)
	ar -rcs $(NAME) $^

libpswap_bonus.a : $(OBJBONUS) $(HEADERDIR)$(HEADERBONUS)
	ar -rcs libpswap_bonus.a $^

libft_printf.a :
	-@${MAKE} -sC ft_printf/

libft.a :
	-@${MAKE} -sC libft/

clean :
	-@rm -f $(OBJ)
	-@rm -f $(OBJBONUS)
	-@${MAKE} clean -sC ft_printf/
	-@${MAKE} clean -sC libft/

fclean : clean
	-@rm -f $(NAME)
	-@rm -f $(BINARY)
	-@rm -f $(BINARY_BONUS)
	-@rm -f libpswap_bonus.a
	-@${MAKE} fclean -sC ft_printf/
	-@${MAKE} fclean -sC libft/

re : fclean all

bre : fclean bonus

.PHONY : all bonus clean fclean re bre
