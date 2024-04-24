# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nandroso <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/01 17:19:28 by nandroso          #+#    #+#              #
#    Updated: 2023/09/01 17:23:43 by nandroso         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 	= libftprintf.a
FLAGS	= -Wall -Wextra -Werror
SRC 	= $(shell find . -iname "*.c")
OBJ 	= $(SRC:%.c=%.o)

%.o: %.c
	cc $(FLAGS) -I. -c $< -o $@

all: $(OBJ)
	ar -rcs $(NAME) $(OBJ)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
