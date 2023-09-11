# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ronanpoder <ronanpoder@student.42.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/11 15:22:15 by ronanpoder        #+#    #+#              #
#    Updated: 2023/09/11 16:47:17 by ronanpoder       ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libasm.a

AS = nasm
CC = nasm

CFLAGS = -Wall -Werror -Wextra
ASFLAGS = -f elf64

SRCS = ./src/strlen.s \

OBJS = ${SRCS:.s=.o}

all: ${NAME}

${NAME}: ${OBJS}
		ar -rcs ${NAME} ${OBJS}

%.o: %.s
	${AS} ${ASFLAGS} $< -o $@

test: ${NAME}
	gcc main.c ${NAME}

clean:
	rm -f ${OBJS}

fclean: clean
	rm -f ${NAME}

re: fclean
	${MAKE} all
