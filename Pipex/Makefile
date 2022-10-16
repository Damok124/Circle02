# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: zharzi <zharzi@student.42angouleme.fr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/06 17:12:24 by zharzi            #+#    #+#              #
#    Updated: 2022/10/16 18:25:47 by zharzi           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libpipex.a

BINARY = pipex

SRCSDIR = ./srcs/

SRCS = \
${SRCSDIR}ft_get_fullpaths.c \
${SRCSDIR}ft_get_validpath.c \
${SRCSDIR}ft_get_tmpname.c \
${SRCSDIR}ft_get_paths.c \
${SRCSDIR}ft_get_next_cmd.c \
${SRCSDIR}ft_free_data.c \
${SRCSDIR}ft_infile_to_stdin.c \
${SRCSDIR}ft_infile_to_stdin_bonus.c \
${SRCSDIR}ft_outfile_to_stdout.c \
${SRCSDIR}ft_outfile_to_stdout_bonus.c \
${SRCSDIR}ft_setup_limiter_bonus.c \
${SRCSDIR}ft_clean_connect.c \
${SRCSDIR}ft_parse_cmd.c

HEADERDIR = includes/

HEADER = pipex.h

OBJ = $(SRCS:.c=.o)

CC = gcc

FLAGS = -Wall -Wextra -Werror -g

IFLAG = -I$(HEADERDIR) -Ift_printf/includes/ -Ilibft/includes/

all : libpipex.a libft_printf.a libft.a
	$(CC) $(FLAGS) main.c $(IFLAG) -L. -lpipex -L./libft -lft -L./ft_printf \
	-lft_printf -o $(BINARY)

test : libpipex.a libft_printf.a libft.a
	$(CC) $(FLAGS) test.c $(IFLAG) -L. -lpipex -L./libft -lft -L./ft_printf \
	-lft_printf -o $(BINARY)_test

bonus : libpipex_bonus.a libft_printf.a libft.a
	$(CC) $(FLAGS) main_bonus.c $(IFLAG) -L. -lpipex_bonus -L./libft -lft -L./ft_printf \
	-lft_printf -o $(BINARY)

%.o : %.c
	$(CC) $(FLAGS) $(IFLAG) -o $@ -c $^

libpipex.a : $(OBJ) $(HEADERDIR)$(HEADER)
	ar -rcs $(NAME) $^

libpipex_bonus.a : $(OBJ) $(HEADERDIR)$(HEADER)
	ar -rcs libpipex_bonus.a $^

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
	rm -f $(BINARY)_test
	${MAKE} fclean -C ft_printf/
	${MAKE} fclean -C libft/

re : fclean all

.PHONY : all clean fclean re
