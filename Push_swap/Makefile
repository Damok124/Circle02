# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: zharzi <zharzi@student.42angouleme.fr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/06 17:12:24 by zharzi            #+#    #+#              #
#    Updated: 2022/07/23 00:33:48 by zharzi           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libpswap.a

BINARY = push_swap

SRCSDIR = ./srcs/

SRCS = $(SRCSDIR)ft_strlen.c

HEADERDIR = includes/

HEADER = pswap.h

OBJ = $(SRCS:.c=.o)

CC = gcc

FLAGS = -Wall -Wextra -Werror

IFLAG = -I$(HEADERDIR)

all : libpswap.a
	-@$(CC) $(FLAGS) main.c $(IFLAG) -L. -lpswap -o $(BINARY)

%.o : %.c
	-@$(CC) $(FLAGS) $(IFLAG) -o $@ -c $^

libpswap.a : $(OBJ) $(HEADERDIR)$(HEADER)
	-@ar -rcs $(NAME) $^

clean :
	-@rm -f $(OBJ)

fclean : clean
	-@rm -f $(NAME)
	-@rm -f $(BINARY)

re : fclean all

.PHONY : all clean fclean re
