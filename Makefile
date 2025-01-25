# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rpoder <rpoder@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/11 15:22:15 by ronanpoder        #+#    #+#              #
#    Updated: 2025/01/25 12:08:08 by rpoder           ###   ########.fr        #
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
		./src/ft_read.s \
		./src/ft_strdup.s \

OBJS = ${SRCS:.s=.o}

all: ${NAME}

${NAME}: ${OBJS}
		ar -rcs ${NAME} ${OBJS}

%.o: %.s
	${AS} ${ASFLAGS} $< -o $@

test: ${NAME}
	cc ${CFLAGS} main.c ${NAME} -o test-libasm

clean:
	rm -f ${OBJS}

fclean: clean
	rm -f ${NAME}
	rm -f test-libasm

re: fclean
	${MAKE} all
