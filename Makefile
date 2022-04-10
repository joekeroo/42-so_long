NAME = so_long

CC = gcc
CFLAGS = -Wall -Wextra -Werror -I.
MLXFLAGS = -lmlx -framework OpenGL -framework AppKit
RM = rm -f

MAIN = main.c
SRC = so_long.c get_next_line.c error/check_file_error.c error/check_map_error.c \
	  error/create_map.c error/check_error.c so_long_utils.c player_control.c \
	  animations/create_images.c enemy_control.c animations/destroy_images.c \
	  animations/animation_utils_a.c animations/animation_utils_b.c \
	  error/check_portals.c animations/handle_images.c death_msg.c
OBJ = ${SRC:.c=.o}

LIBFT_PATH = libft/
LIBFT = libft/libft.a
PRINTF_PATH = libftprintf/
PRINTF = libftprintf/libftprintf.a

all: ${NAME}

${NAME}: ${OBJ} ${LIBFT} ${PRINTF}
	${CC} ${CFLAGS} ${MAIN} ${MLXFLAGS} ${OBJ} ${LIBFT} ${PRINTF} -o ${NAME}

${LIBFT}:
	make re -C ${LIBFT_PATH}

${PRINTF}:
	make re -C ${PRINTF_PATH}

clean:
	${RM} ${OBJ}
	make clean -C ${LIBFT_PATH}
	make clean -C ${PRINTF_PATH}

fclean: clean
	${RM} ${NAME}
	make fclean -C ${LIBFT_PATH}
	make fclean -C ${PRINTF_PATH}

re: fclean all

.PHONY = all clean fclean re
