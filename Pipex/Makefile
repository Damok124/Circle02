# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: zharzi <zharzi@student.42angouleme.fr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/06 17:12:24 by zharzi            #+#    #+#              #
#    Updated: 2022/09/27 12:09:26 by zharzi           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libpipex.a

BINARY = pipex

SRCSDIR = ./srcs/

SRCS = ${SRCSDIR}test.c

HEADERDIR = includes/

HEADER = pipex.h

OBJ = $(SRCS:.c=.o)

CC = gcc

FLAGS = -Wall -Wextra -Werror -g

IFLAG = -I$(HEADERDIR) -Ift_printf/includes/ -Ilibft/includes/

all : libpipex.a libft_printf.a libft.a
	$(CC) $(FLAGS) main.c $(IFLAG) -L. -lpipex -L./libft -lft -L./ft_printf \
	-lft_printf -o $(BINARY)

%.o : %.c
	$(CC) $(FLAGS) $(IFLAG) -o $@ -c $^

libpipex.a : $(OBJ) $(HEADERDIR)$(HEADER)
	ar -rcs $(NAME) $^

libft_printf.a :
	${MAKE} -C ft_printf/

libft.a :
	${MAKE} -C libft/

clean :
	rm -f $(OBJ)
	${MAKE} clean -C ft_printf/
	${MAKE} clean -C libft/

fclean : clean
	rm -f $(NAME)
	rm -f $(BINARY)
	${MAKE} fclean -C ft_printf/
	${MAKE} fclean -C libft/

re : fclean all

.PHONY : all clean fclean re
