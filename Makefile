SRCS	= event.c gnl_aux.c gnl.c graphics.c lst.c main.c mapping.c parsing.c path_finding.c

OBJS	= ${SRCS:.c=.o}

NAME	= game

CC		= gcc

RM		= rm -f

CFLAGS	= -Wall -Wextra -Werror

.c.o:
			${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

${NAME}:	${OBJS}
			${CC} -o ${NAME} ${OBJS} minilibx-linux/libmlx_Linux.a -L -I minilibx-linux/mlx.h -lXext -lX11 -lm

all:		${NAME}

clean:
			${RM} ${OBJS}

fclean:		clean
			${RM} ${NAME}

re:			fclean all

.PHONY:		all clean fclean re
