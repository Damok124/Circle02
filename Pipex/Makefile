# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: zharzi <zharzi@student.42angouleme.fr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/06 17:12:24 by zharzi            #+#    #+#              #
#    Updated: 2022/12/27 18:03:30 by zharzi           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libpipex.a

BINARY = pipex

SRCSDIR = ./srcs/

SRCSBONUSDIR = ./srcs_bonus/

SRCS = \
${SRCSDIR}ft_get_paths.c \
${SRCSDIR}ft_parse_cmd.c \
${SRCSDIR}ft_clean_connect.c \
${SRCSDIR}ft_cmd_not_found.c \
${SRCSDIR}ft_such_file.c \
${SRCSDIR}ft_infile_permission.c \
${SRCSDIR}ft_outfile_permission.c \
${SRCSDIR}ft_close_stdfds.c \
${SRCSDIR}ft_double_fullfree.c \
${SRCSDIR}ft_infile_to_in.c \
${SRCSDIR}ft_get_goodpath.c \
${SRCSDIR}ft_get_fullpaths.c \
${SRCSDIR}ft_get_validpaths.c \
${SRCSDIR}ft_outfile_to_out.c \
${SRCSDIR}ft_test_files.c \
${SRCSDIR}ft_print_cmderr.c \
${SRCSDIR}ft_init_data.c

SRCSBONUS = \
${SRCSBONUSDIR}ft_cmd_not_found_bonus.c \
${SRCSBONUSDIR}ft_such_file_bonus.c \
${SRCSBONUSDIR}ft_close_stdfds_bonus.c \
${SRCSBONUSDIR}ft_print_cmderr_bonus.c \
${SRCSBONUSDIR}ft_parse_cmd_bonus.c \
${SRCSBONUSDIR}ft_double_fullfree_bonus.c \
${SRCSBONUSDIR}ft_clean_exit_bonus.c \
${SRCSBONUSDIR}ft_outfile_to_out_bonus.c \
${SRCSBONUSDIR}ft_append_to_outfile_bonus.c \
${SRCSBONUSDIR}ft_outfile_permission_bonus.c \
${SRCSBONUSDIR}ft_init_data_bonus.c \
${SRCSBONUSDIR}ft_infile_to_in_bonus.c \
${SRCSBONUSDIR}ft_get_goodpath_bonus.c \
${SRCSBONUSDIR}ft_get_fullpaths_bonus.c \
${SRCSBONUSDIR}ft_infile_permission_bonus.c \
${SRCSBONUSDIR}ft_test_files_bonus.c \
${SRCSBONUSDIR}ft_get_validpaths_bonus.c \
${SRCSBONUSDIR}ft_get_paths_bonus.c \
${SRCSBONUSDIR}ft_clean_connect_bonus.c \
${SRCSBONUSDIR}ft_check_tmpname_bonus.c \
${SRCSBONUSDIR}ft_get_tmpname_bonus.c \
${SRCSBONUSDIR}ft_heredoc_to_file_bonus.c \
${SRCSBONUSDIR}ft_setup_limiter_bonus.c \
${SRCSBONUSDIR}ft_heredoc_to_in_bonus.c \
${SRCSBONUSDIR}ft_parent_hdoc_bonus.c \
${SRCSBONUSDIR}ft_unlink_and_free_bonus.c

HEADERDIR = includes/

HEADER = pipex.h

HEADERBONUS = pipex_bonus.h

OBJ = $(SRCS:.c=.o)

OBJBONUS = $(SRCSBONUS:.c=.o)

CC = clang

FLAGS = -Wall -Wextra -Werror -g3

IFLAG = -I$(HEADERDIR) -Ift_printf/includes/ -Ilibft/includes/

all : libpipex.a libft_printf.a libft.a $(BINARY)

$(BINARY):
	$(CC) $(FLAGS) main.c $(IFLAG) -L. -lpipex -L./libft -lft -L./ft_printf \
		-lft_printf -o $(BINARY)

bonus : libpipex_bonus.a libft_printf.a libft.a
	$(CC) $(FLAGS) main_bonus.c $(IFLAG) -L. -lpipex_bonus -L./libft -lft \
		-L./ft_printf -lft_printf -o $(BINARY)

%.o : %.c
	$(CC) $(FLAGS) $(IFLAG) -o $@ -c $^

libpipex.a : $(OBJ) $(HEADERDIR)$(HEADER)
	ar -rcs $(NAME) $^

libpipex_bonus.a : $(OBJBONUS) $(HEADERDIR)$(HEADERBONUS)
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

.PHONY : all bonus clean fclean re bre
