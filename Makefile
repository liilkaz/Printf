# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tacarlen <tacarlen@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/04/20 13:21:11 by tacarlen          #+#    #+#              #
#    Updated: 2021/05/17 10:42:05 by tacarlen         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= libftprintf.a

SRCS	= ft_utils.c ft_type_number.c ft_for_int_functions.c \
			ft_itoa.c ft_for_parser.c ft_for_string.c \
			ft_for_int.c ft_printf.c ft_for_pointer.c

OBJS	= ${SRCS:.c=.o}

HEADER	= ft_printf.h

RM		= rm -f

GCC		= gcc

FLAGS	= -Wall -Wextra -Werror

.c.o:	${HEADER}
		${GCC} ${CFLAGS} -c $< -o $@

${NAME}:	${OBJS} ${HEADER}
			ar rc ${NAME} ${OBJS}
			ranlib ${NAME}

all: 	${NAME}

clean:
		${RM} ${OBJS}

fclean:	clean
		${RM} ${NAME}

re:		fclean clean all

.PHONY : all clean fclean re
