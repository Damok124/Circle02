# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: zharzi <zharzi@student.42angouleme.fr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/06 17:12:24 by zharzi            #+#    #+#              #
#    Updated: 2022/08/02 19:50:39 by zharzi           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SRCSDIR = ./srcs/

SRCS = $(SRCSDIR)ft_memset.c \
$(SRCSDIR)ft_bzero.c \
$(SRCSDIR)ft_memcpy.c \
$(SRCSDIR)ft_memmove.c \
$(SRCSDIR)ft_memchr.c \
$(SRCSDIR)ft_memcmp.c \
$(SRCSDIR)ft_strlen.c \
$(SRCSDIR)ft_isalpha.c \
$(SRCSDIR)ft_isdigit.c \
$(SRCSDIR)ft_isalnum.c \
$(SRCSDIR)ft_isascii.c \
$(SRCSDIR)ft_isprint.c \
$(SRCSDIR)ft_toupper.c \
$(SRCSDIR)ft_tolower.c \
$(SRCSDIR)ft_strchr.c \
$(SRCSDIR)ft_strrchr.c \
$(SRCSDIR)ft_strncmp.c \
$(SRCSDIR)ft_strlcpy.c \
$(SRCSDIR)ft_strlcat.c \
$(SRCSDIR)ft_strnstr.c \
$(SRCSDIR)ft_atoi.c \
$(SRCSDIR)ft_calloc.c \
$(SRCSDIR)ft_check_int.c \
$(SRCSDIR)ft_strdup.c \
$(SRCSDIR)ft_substr.c \
$(SRCSDIR)ft_strjoin.c \
$(SRCSDIR)ft_strtrim.c \
$(SRCSDIR)ft_split.c \
$(SRCSDIR)ft_itoa.c \
$(SRCSDIR)ft_strmapi.c \
$(SRCSDIR)ft_putchar_fd.c \
$(SRCSDIR)ft_putstr_fd.c \
$(SRCSDIR)ft_putendl_fd.c \
$(SRCSDIR)ft_putnbr_fd.c \
$(SRCSDIR)ft_putnbr_base_fd.c \
$(SRCSDIR)ft_striteri.c \
$(SRCSDIR)ft_lstnew.c \
$(SRCSDIR)ft_lstadd_front.c \
$(SRCSDIR)ft_lstsize.c \
$(SRCSDIR)ft_lstlast.c \
$(SRCSDIR)ft_lstadd_back.c \
$(SRCSDIR)ft_lstdelone.c \
$(SRCSDIR)ft_lstclear.c \
$(SRCSDIR)ft_lstiter.c \
$(SRCSDIR)ft_lstmap.c \
$(SRCSDIR)ft_full_free.c \
$(SRCSDIR)ft_true_free.c \
$(SRCSDIR)ft_chartab_len.c \
$(SRCSDIR)ft_inttab_len.c \
$(SRCSDIR)ft_check_int_dup.c \
$(SRCSDIR)ft_check_strs_int.c \
$(SRCSDIR)ft_strs_to_tab.c \
$(SRCSDIR)ft_atoi_safe.c

HEADERDIR = includes/

HEADER = libft.h

OBJ = $(SRCS:.c=.o)

CC = gcc

FLAGS = -Wall -Wextra -Werror -ggdb

IFLAG = -I$(HEADERDIR)

all : ${NAME}

%.o : %.c
	-@$(CC) $(FLAGS) $(IFLAG) -o $@ -c $^

libft.a : $(OBJ) $(HEADERDIR)$(HEADER)
	-@ar -rcs $(NAME) $^

clean :
	-@rm -f $(OBJ)

fclean : clean
	-@rm -f $(NAME)
	-@rm -f $(BINARY)

re : fclean all

.PHONY : all clean fclean re
