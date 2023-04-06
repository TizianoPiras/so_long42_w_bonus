# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tpiras <tpiras@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/17 13:43:33 by tpiras            #+#    #+#              #
#    Updated: 2023/04/04 15:00:47 by tpiras           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

HEADER = ${NAME:.a=.h}

SOURCES = ft_strlen.c \
ft_strdup.c \
ft_substr.c \
ft_split.c \
ft_itoa.c \

OBJECTS = ${SOURCES:.c=.o}

LIBC = ar rcs

CC = gcc

RM = rm -f

CFLAGS = -Wall -Werror -Wextra

.o:.c
		@${CC} ${CFLAGS} ${OBJECTS} $< -o ${<:.c=.o}

${NAME}: ${OBJECTS}
		@${LIBC} ${NAME} ${OBJECTS}
		@ranlib ${NAME}

all: ${NAME}

clean:
		@${RM} ${OBJECTS}

fclean: clean
		@${RM} ${NAME}

re: fclean all
