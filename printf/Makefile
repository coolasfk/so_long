# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: eprzybyl <eprzybyl@student.42lausanne.c    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/13 13:43:01 by eprzybyl          #+#    #+#              #
#    Updated: 2024/01/15 23:44:28 by eprzybyl         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

CC = gcc

FLAGS = -Wall -Werror -Wextra

HEADER = ft_printf.h

RM = rm -f

AR = ar rcs

SRC := $(wildcard *.c)


%.o: %.c $(HEADER)
	
	$(CC) $(FLAGS) -c $< -o $@

	
OBJ = $(SRC:%.c=%.o)


$(NAME): $(OBJ)
	$(AR) $(NAME) $(OBJ)


.PHONY: all clean fclean re

all: $(NAME)

clean:
	$(RM) $(OBJ) $(NAME)

fclean: clean

re: fclean all
