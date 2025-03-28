
LIBFT_PATH		=	./libraries/libft
LIBFT			=	$(LIBFT_PATH)/libft.a

PRINTF_PATH     =  	libraries/ft_printf

SOURCES_FILES	=	so_long.c \
					argv_checker.c \
					rendering.c \
					init_game.c \
					read_map.c \
					map_validate.c \
					player_moves.c \
					start_game.c \
					exit_game.c	\
					map_helper.c \
					check_exit_position.c \

HEADER			=	so_long.h

SOURCES			=	$(SOURCES_FILES)

OBJECTS			= 	$(SOURCES:.c=.o)

PRINTF_OBJS     =  	$(PRINTF_PATH)/*.o

NAME			=	so_long

CC				=	cc
RM				=	rm -f

CFLAGS			=	-Wall -Wextra -Werror
MLXFLAGS		=	-L/usr/include/minilibx-linux -lmlx -lX11 -lXext

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

all:			$(NAME)

$(NAME):		$(LIBFT) $(PRINTF_OBJS) $(OBJECTS) $(HEADER)
				$(CC) $(CFLAGS) $(OBJECTS) $(LIBFT) $(PRINTF_OBJS) $(MLXFLAGS) -o $(NAME)

$(LIBFT):
				$(MAKE) -C $(LIBFT_PATH)


$(PRINTF_OBJS):
				$(MAKE) -C $(PRINTF_PATH)

clean:
				$(MAKE) -C $(LIBFT_PATH) clean
				$(MAKE) -C $(PRINTF_PATH) clean
				$(RM) $(OBJECTS)

fclean:			clean
				$(MAKE) -C $(LIBFT_PATH) fclean
				$(MAKE) -C $(PRINTF_PATH) fclean
				$(RM) $(NAME)

re:				fclean all

.PHONY:			all clean fclean re libft printf

.SECONDARY:  $(OBJECTS) $(PRINTF_OBJS) $(LIBFT_PATH)/*.o