# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: zharzi <zharzi@student.42angouleme.fr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/06 17:12:24 by zharzi            #+#    #+#              #
#    Updated: 2022/07/24 17:59:50 by zharzi           ###   ########.fr        #
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
${SRCSDIR}ft_move_rrr.c

HEADERDIR = includes/

HEADER = pswap.h

OBJ = $(SRCS:.c=.o)

CC = gcc

FLAGS = -Wall -Wextra -Werror -g

IFLAG = -I$(HEADERDIR) -Ift_printf/includes/ -Ilibft/includes/

all : libpswap.a libft_printf.a libft.a
	-@$(CC) $(FLAGS) main.c $(IFLAG) -L. -lpswap -L./ft_printf -lft_printf \
	-L./libft -lft -o $(BINARY)

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