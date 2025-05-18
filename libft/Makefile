# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: oel-jrao <oel-jrao@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/03 22:55:06 by oel-jrao          #+#    #+#              #
#    Updated: 2024/11/05 18:33:05 by oel-jrao         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC = ft_atoi.c ft_bzero.c ft_calloc.c ft_isalnum.c ft_isalpha.c ft_isascii.c ft_isdigit.c ft_isprint.c ft_itoa.c ft_memchr.c ft_memcmp.c ft_memcpy.c  ft_memmove.c  ft_memset.c ft_putchar_fd.c ft_putendl_fd.c ft_putnbr_fd.c ft_putstr_fd.c ft_split.c ft_strchr.c ft_strdup.c ft_striteri.c ft_strjoin.c ft_strlcat.c ft_strlcpy.c ft_strlen.c ft_strmapi.c ft_strncmp.c ft_strnstr.c ft_strrchr.c ft_strtrim.c ft_substr.c ft_tolower.c ft_toupper.c

BONUS = ft_lstnew_bonus.c ft_lstadd_front_bonus.c ft_lstsize_bonus.c ft_lstlast_bonus.c ft_lstadd_back_bonus.c ft_lstdelone_bonus.c ft_lstclear_bonus.c ft_lstiter_bonus.c ft_lstmap_bonus.c

CC = cc
CFLAGS = -Wall -Wextra -Werror

OBJ = ${SRC:.c=.o}
OBONUS = ${BONUS:.c=.o}
NAME = libft.a

all: ${NAME} 
##################################### 
NAME: ${NAME}
# compile and archive main objects
${NAME}: ${OBJ}
	ar -rcs ${NAME} ${OBJ}

# Rule to build bonus objects and add them to the library
bonus: ${OBONUS}
	ar -rcs ${NAME} ${OBONUS}

#compile bonus files separately
${OBONUS}:
	${CC} ${CFLAGS} -c $(BONUS)
	#ar -rcs ${NAME} ${OBONUS}

# clean up object files 
clean:
	rm -rf ${OBJ} ${OBONUS}

# clean and remove the library
fclean: clean
	rm -rf ${NAME}

#rebuild everything from scratch
re: fclean all
	
.PHONY: all clean fclean re bonus

# to make this target executed by default, not the first target
# .DEFAULT_GOAL := clean

# create symbol index
indexing:${OBONUS}
	ranlib ${NAME}
# Display symbols of the library
symbol:${NAME}
	nm ${NAME}
