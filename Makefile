SRCS_DIR	= src/

SRC			= event.c gnl_aux.c gnl.c graphics.c lst.c main.c mapping.c parsing.c path_finding.c

SRCS		= $(addprefix $(SRCS_DIR), $(SRC))

OBJS_DIR	= obj/

OBJ			= ${SRC:.c=.o}

OBJS		= $(addprefix $(OBJS_DIR), $(OBJ))

NAME		= so_long

CC			= gcc

CFLAGS		= -Wall -Wextra -Werror

MLX			= minilibx-linux/libmlx_Linux.a -L -I minilibx-linux/mlx.h -lXext -lX11 -lm

INCS		= -I ./include/

all:		${OBJS_DIR} ${NAME}

${OBJS_DIR}:
			mkdir ${OBJS_DIR}

${OBJS_DIR}%.o: ${SRCS_DIR}%.c
			${CC} ${CFLAGS} -c $< -o $@ ${INCS}

${NAME}:	${OBJS}
			${CC} ${FLAGS} ${OBJS} ${MLX} -o ${NAME}

clean:
			rm -rf ${OBJS_DIR}

fclean:		clean
			rm -f ${NAME}

re:			fclean all

.PHONY:		all clean fclean re
