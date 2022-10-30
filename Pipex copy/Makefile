# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: zharzi <zharzi@student.42angouleme.fr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/06 17:12:24 by zharzi            #+#    #+#              #
#    Updated: 2022/10/21 17:04:18 by zharzi           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libpipex.a

BINARY = pipex

SRCSDIR = ./srcs/

SRCSBONUSDIR = ./srcs_bonus/

SRCS = \
${SRCSDIR}ft_err_msg.c \
${SRCSDIR}ft_print_error_msg.c \
${SRCSDIR}ft_init_data.c \
${SRCSDIR}ft_cmd_not_found.c \
${SRCSDIR}ft_get_fullpaths.c \
${SRCSDIR}ft_get_validpath.c \
${SRCSDIR}ft_get_paths.c \
${SRCSDIR}ft_get_next_cmd.c \
${SRCSDIR}ft_free_data.c \
${SRCSDIR}ft_infile_to_stdin.c \
${SRCSDIR}ft_outfile_to_stdout.c \
${SRCSDIR}ft_clean_connect.c \
${SRCSDIR}ft_parse_cmd.c

SRCSBONUS = \
${SRCSDIR}ft_get_tmpname_bonus.c \
${SRCSDIR}ft_init_data_bonus.c \
${SRCSDIR}ft_infile_to_stdin_bonus.c \
${SRCSDIR}ft_outfile_to_stdout_bonus.c \
${SRCSDIR}ft_setup_limiter_bonus.c \
${SRCSDIR}ft_get_validpath_bonus.c \
${SRCSDIR}ft_get_next_cmd_bonus.c

HEADERDIR = includes/

HEADER = pipex.h

HEADERBONUS = pipex_bonus.h

OBJ = $(SRCS:.c=.o)

OBJBONUS = $(SRCSBONUS:.c=.o)

CC = gcc

FLAGS = -Wall -Wextra -Werror -g3

IFLAG = -I$(HEADERDIR) -Ift_printf/includes/ -Ilibft/includes/

all : libpipex.a libft_printf.a libft.a $(BINARY)

$(BINARY):
	$(CC) $(FLAGS) main.c $(IFLAG) -L. -lpipex -L./libft -lft -L./ft_printf \
		-lft_printf -o $(BINARY)

test : libpipex.a libft_printf.a libft.a
	$(CC) $(FLAGS) test.c $(IFLAG) -L. -lpipex -L./libft -lft -L./ft_printf \
		-lft_printf -o $(BINARY)_test

bonus : libpipex_bonus.a libft_printf.a libft.a
	$(CC) $(FLAGS) main_bonus.c $(IFLAG) -L. -lpipex_bonus -L./libft -lft \
		-L./ft_printf -lft_printf -o $(BINARY)

%.o : %.c
	$(CC) $(FLAGS) $(IFLAG) -o $@ -c $^

libpipex.a : $(OBJ) $(HEADERDIR)$(HEADER)
	ar -rcs $(NAME) $^

libpipex_bonus.a : $(OBJ) $(OBJBONUS) $(HEADERDIR)$(HEADERBONUS)
	ar -rcs libpipex_bonus.a $^

libft_printf.a :
	@${MAKE} -sC ft_printf/

libft.a :
	@${MAKE} -sC libft/

clean :
	rm -f $(OBJ)
	rm -f $(OBJBONUS)
	@${MAKE} clean -sC ft_printf/
	@${MAKE} clean -sC libft/

fclean : clean
	rm -f $(NAME)
	rm -f $(BINARY)
	rm -f libpipex_bonus.a
	@${MAKE} fclean -sC ft_printf/
	@${MAKE} fclean -sC libft/

re : fclean all

bre : fclean bonus

.PHONY : all clean fclean re bre
