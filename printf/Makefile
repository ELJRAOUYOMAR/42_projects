# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: oel-jrao <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/27 15:23:31 by oel-jrao          #+#    #+#              #
#    Updated: 2024/12/04 12:08:14 by oel-jrao         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC = ft_printf.c ft_puts.c ft_hexa_puts.c ft_put_adresse.c 

NAME = libftprintf.a
CC = cc
CFLAGS = -Wall -Wextra -Werror
OSRC = ${SRC:.c=.o}

all: ${NAME}

${NAME}: ${OSRC}
	ar -rcs ${NAME} ${OSRC}

%.o:%.c libftprintf.h
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf ${OSRC}

fclean: clean
	rm -rf ${NAME}

re: fclean all

.PHONY: all clean fclean re
