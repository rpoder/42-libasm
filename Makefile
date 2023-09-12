# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rpoder <rpoder@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/11 15:22:15 by ronanpoder        #+#    #+#              #
#    Updated: 2023/09/12 18:18:11 by rpoder           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libasm.a

AS = nasm
CC = nasm

CFLAGS = -Wall -Werror -Wextra
ASFLAGS = -f elf64

SRCS =	./src/ft_strlen.s \
		./src/ft_strcpy.s \
		./src/ft_strcmp.s \
		./src/ft_write.s \

OBJS = ${SRCS:.s=.o}

all: ${NAME}

${NAME}: ${OBJS}
		ar -rcs ${NAME} ${OBJS}

%.o: %.s
	${AS} ${ASFLAGS} $< -o $@

test: ${NAME}
	cc main.c ${NAME}

clean:
	rm -f ${OBJS}

fclean: clean
	rm -f ${NAME}

re: fclean
	${MAKE} all
