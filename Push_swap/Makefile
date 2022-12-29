# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: zharzi <zharzi@student.42angouleme.fr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/06 17:12:24 by zharzi            #+#    #+#              #
#    Updated: 2022/12/29 01:47:06 by zharzi           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libpswap.a

BINARY = push_swap

BINARY_BONUS = checker

SRCSDIR = ./srcs/

SRCSBONUSDIR = ./srcs_bonus/

SRCS = \
${SRCSDIR}test.c

SRCSBONUS = \
${SRCSBONUSDIR}test.c

HEADERDIR = includes/

HEADER = pswap.h

HEADERBONUS = pswap_bonus.h

OBJ = $(SRCS:.c=.o)

OBJBONUS = $(SRCSBONUS:.c=.o)

CC = clang

FLAGS = -Wall -Wextra -Werror -g3 -gdwarf-4

IFLAG = -I$(HEADERDIR) -Ift_printf/includes/ -Ilibft/includes/

all : ${BINARY}

${BINARY} : ${NAME} libft_printf.a libft.a
	-@$(CC) $(FLAGS) main.c $(IFLAG) -L. -lpswap -L./libft -lft -L./ft_printf \
	-lft_printf -o $(BINARY)

bonus : ${BINARY_BONUS}

${BINARY_BONUS} : libpswap_bonus.a libft_printf.a libft.a
	-@$(CC) $(FLAGS) main_bonus.c $(IFLAG) -L. -lpswap_bonus -L./libft -lft \
	-L./ft_printf -lft_printf -o $(BINARY_BONUS)

%.o : %.c
	-@$(CC) $(FLAGS) $(IFLAG) -o $@ -c $^

${NAME} : $(OBJ) $(HEADERDIR)$(HEADER)
	-@ar -rcs $(NAME) $^

libpswap_bonus.a : $(OBJBONUS) $(HEADERDIR)$(HEADERBONUS)
	ar -rcs libpswap_bonus.a $^

libft_printf.a :
	-@${MAKE} -C ft_printf/

libft.a :
	-@${MAKE} -C libft/

clean :
	-@rm -f $(OBJ)
	-@rm -f $(OBJBONUS)
	-@${MAKE} clean -C ft_printf/
	-@${MAKE} clean -C libft/

fclean : clean
	-@rm -f $(NAME)
	-@rm -f $(BINARY)
	-@rm -f $(BINARY_BONUS)
	-@rm -f libpswap_bonus.a
	-@${MAKE} fclean -C ft_printf/
	-@${MAKE} fclean -C libft/

re : fclean all

bre : fclean bonus

.PHONY : all bonus clean fclean re bre
