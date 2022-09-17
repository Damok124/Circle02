# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: zharzi <zharzi@student.42angouleme.fr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/31 13:40:41 by zharzi            #+#    #+#              #
#    Updated: 2022/09/15 22:29:22 by zharzi           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libfdf.a

BINARY = fdf

SRCSDIR = ./srcs/

SRCS = ${SRCSDIR}ft_test.c \
${SRCSDIR}ft_fdf_free_matrix.c \
${SRCSDIR}ft_frame.c \
${SRCSDIR}ft_fdf_rowcount.c \
${SRCSDIR}ft_fdf_getlen.c \
${SRCSDIR}ft_fdf_lencheck.c \
${SRCSDIR}ft_get_octant.c \
${SRCSDIR}ft_pix_is_visible.c \
${SRCSDIR}ft_trace_oct.c \
${SRCSDIR}ft_link.c \
${SRCSDIR}ft_base_key.c \
${SRCSDIR}ft_manual_color.c \
${SRCSDIR}ft_renew_image.c \
${SRCSDIR}ft_keypress.c \
${SRCSDIR}ft_click_cross.c \
${SRCSDIR}ft_end_mlx.c \
${SRCSDIR}ft_pixel_put.c \
${SRCSDIR}ft_dot.c

HEADERDIR = includes/

HEADER = fdf.h

OBJ = $(SRCS:.c=.o)

CC = gcc

FLAGS = -Wall -Wextra -Werror -g

IFLAG = -I$(HEADERDIR) -Ift_printf/includes/ -Ilibft/includes/ -Imlx/

all : libmlx.a libfdf.a libft_printf.a libft.a
	$(CC) $(FLAGS) main.c $(IFLAG) -L. -lfdf -L./mlx -lmlx -lXext -lX11 \
	-L./libft -lft -L./ft_printf -lft_printf -o $(BINARY)

%.o : %.c
	$(CC) $(FLAGS) $(IFLAG) -o $@ -c $^

libfdf.a : $(OBJ) $(HEADERDIR)$(HEADER)
	ar -rcs $(NAME) $^

libft_printf.a :
	${MAKE} -C ft_printf/

libft.a :
	${MAKE} -C libft/

libmlx.a :
	${MAKE} -C mlx/

clean :
	rm -f $(OBJ)
	${MAKE} clean -C ft_printf/
	${MAKE} clean -C libft/
	${MAKE} clean -C mlx/

fclean : clean
	rm -f $(NAME)
	rm -f $(BINARY)
	${MAKE} fclean -C ft_printf/
	${MAKE} fclean -C libft/
	${MAKE} clean -C mlx/

re : fclean all

.PHONY : all clean fclean re
