NAME = fdf

SRCS =	main.c \
		parse_grid.c \
		create_plane.c \
		check_file_name.c \
		open_close_window.c \
		init/init_map.c \
		init/init_coord.c \
		init/init_grid.c \
		init/init_plane.c \
		init/init_vect.c \
		upd/upd_grid.c \
		utils/free_close_exit.c \
		utils/free_map.c \
		utils/clean_and_exit.c \
		utils/get_grid_len.c \
		utils/get_color.c \
		print/print_grid.c \
		print/print_coords.c \
		print/print_plane.c \

OBJS = ${addprefix ${OBJS_DIR}/,${SRCS:.c=.o}}

OBJS_DIR = obj

LIBFT_PATH = ./Libft

LIBFT_NAME = libft.a

MINILIBX_PATH = ./Minilibx

MINILIBX_NAME = libmlx.a

CC = gcc -g3

CFLAGS = -Wall -Wextra -Werror

INCLUDES = fdf.h

${OBJS_DIR}/%.o:%.c ${INCLUDES}
	@mkdir -p ${dir $@}
	${CC} ${CFLAGS} -c $< -o $@

all: ${NAME}

${NAME}: ${OBJS} ${LIBFT_PATH}/${LIBFT_NAME} ${MINILIBX_PATH}/${MINILIBX_NAME}
	${CC} ${CFLAGS} -o ${NAME} ${OBJS} -L${LIBFT_PATH} -lft -L${MINILIBX_PATH} -lmlx -lXext -lX11 -lm

${LIBFT_PATH}/${LIBFT_NAME}:
	make -C ${LIBFT_PATH}

${MINILIBX_PATH}/${MINILIBX_NAME}:
	make -C ${MINILIBX_PATH}

clean:
	rm -r ${OBJS_DIR}
	make clean -C ${MINILIBX_PATH}
	make clean -C ${LIBFT_PATH}

fclean: clean
	rm -f ${NAME}
	rm -f ${LIBFT_PATH}/${LIBFT_NAME}
	rm -f ${MINILIBX_PATH}/${MINILIBX_NAME}

re: fclean all

.PHONY: all re clean fclean
