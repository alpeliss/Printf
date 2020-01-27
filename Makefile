SRCDIR	= ./srcs/

SRCNAME	=	ft_printf.c				\
			find_tags.c				\
			ft_printf_atoi.c		\
			find_specifier.c

SRCS	=	${addprefix ${SRCDIR}, ${SRCNAME}}


OBJS	= ${SRCS:.c=.o}

INCDIR	=./includes/
NAME	= libftprintf.a

CC	= gcc
RM	= rm -f

CFLAGS	= -Wall -Wextra -Werror


.c.o:
	${CC} ${CFLAGS} -I ${INCDIR} -c $<  -o ${<:.c=.o}

${NAME}:  ${OBJS} 
	ar rc ${NAME} ${OBJS} ${LIB}

all: 	${NAME}

clean:
	${RM} ${OBJS} ${BOBJ}

fclean:		clean
	${RM} ${NAME}

re:		fclean all

c:		all clean

.PHONY:	clean fclean re all
