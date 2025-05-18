NAME			=	push_swap

CC  			=	cc
RM				=	rm -rf
CFLAGS			=	-Wall -Wextra -Werror


SOURCE_FILES	=	ft_split.c \
					operations1.c \
					operations2.c \
					parse_utils_helper.c \
					parse_utils.c \
					parser.c \
					push_swap.c \
					sort_utils.c \
					sort_utils2.c \
					sorting.c \
					stack_utils.c \

SRCS			=	${SOURCE_FILES}

OBJS			= 	${SRCS:.c=.o}

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

clean: 
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re

.SECONDARY: $(OBJS)