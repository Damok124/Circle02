# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: zharzi <zharzi@student.42angouleme.fr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/06 17:12:24 by zharzi            #+#    #+#              #
#    Updated: 2022/08/30 15:08:10 by zharzi           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libpswap.a

BINARY = push_swap

SRCSDIR = ./srcs/

SRCS = ${SRCSDIR}ft_move_sa.c \
${SRCSDIR}ft_move_sb.c \
${SRCSDIR}ft_move_ss.c \
${SRCSDIR}ft_move_pa.c \
${SRCSDIR}ft_move_pb.c \
${SRCSDIR}ft_move_ra.c \
${SRCSDIR}ft_move_rb.c \
${SRCSDIR}ft_move_rr.c \
${SRCSDIR}ft_move_rra.c \
${SRCSDIR}ft_move_rrb.c \
${SRCSDIR}ft_move_rrr.c \
${SRCSDIR}ft_pswap_join.c \
${SRCSDIR}ft_pswap_check_args.c \
${SRCSDIR}ft_pswap_intfinder.c \
${SRCSDIR}ft_pswap_parsing.c \
$(SRCSDIR)ft_ending_bstack.c \
$(SRCSDIR)ft_ending_eastack.c \
$(SRCSDIR)ft_fill_controlval.c \
$(SRCSDIR)ft_pswap_final.c \
$(SRCSDIR)ft_moves_forward.c \
$(SRCSDIR)ft_swap_top_test.c \
$(SRCSDIR)ft_swap_test_b.c \
$(SRCSDIR)ft_test_index.c \
$(SRCSDIR)ft_first_estack.c \
$(SRCSDIR)ft_stack_check_order.c \
$(SRCSDIR)ft_lock_elem.c \
$(SRCSDIR)ft_homing_max.c \
$(SRCSDIR)ft_homing_booster.c \
$(SRCSDIR)ft_is_lock.c \
$(SRCSDIR)ft_small.c \
$(SRCSDIR)ft_get_back_if.c \
$(SRCSDIR)ft_get_back_eb.c \
$(SRCSDIR)ft_index_comp.c \
$(SRCSDIR)ft_moves_backward.c \
$(SRCSDIR)ft_series_length.c \
$(SRCSDIR)ft_put_end.c

HEADERDIR = includes/

HEADER = pswap.h

OBJ = $(SRCS:.c=.o)

CC = gcc

FLAGS = -Wall -Wextra -Werror -g

IFLAG = -I$(HEADERDIR) -Ift_printf/includes/ -Ilibft/includes/

all : libpswap.a libft_printf.a libft.a
	-@$(CC) $(FLAGS) main.c $(IFLAG) -L. -lpswap -L./libft -lft -L./ft_printf \
	-lft_printf -o $(BINARY)

%.o : %.c
	-@$(CC) $(FLAGS) $(IFLAG) -o $@ -c $^

libpswap.a : $(OBJ) $(HEADERDIR)$(HEADER)
	-@ar -rcs $(NAME) $^

libft_printf.a :
	-@${MAKE} -C ft_printf/

libft.a :
	-@${MAKE} -C libft/

clean :
	-@rm -f $(OBJ)
	-@${MAKE} clean -C ft_printf/
	-@${MAKE} clean -C libft/

fclean : clean
	-@rm -f $(NAME)
	-@rm -f $(BINARY)
	-@${MAKE} fclean -C ft_printf/
	-@${MAKE} fclean -C libft/

re : fclean all

.PHONY : all clean fclean re
