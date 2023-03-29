# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tpiras <tpiras@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/24 14:09:36 by tpiras            #+#    #+#              #
#    Updated: 2023/03/27 18:44:05 by tpiras           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

HEADER = $(NAME:.a=.h)

SOURCES = so_long.c \
map.c \
game.c \
movement.c \
libft/ft_split.c \
libft/ft_strlen.c \
libft/ft_substr.c \
enemy_movement.c \
death_animation.c \
door_animation.c \


OBJ = $(SOURCES:.c=.o)

LIBC = ar rcs
LIBFT = libft/libft.a

CC = gcc

RM = rm -f

CFLAGS = -Wall -Werror -Wextra -Imlx -g

all: $(LIBFT) $(NAME) 

$(NAME): $(OBJ)
	$(CC) $(OBJ) -Lmlx -lmlx -framework OpenGL -framework AppKit -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(LIBFT):
		@make -C libft

clean:
		@make clean -C libft
		@$(RM) $(OBJ)

fclean: clean
		@make fclean -C libft
		@$(RM) $(NAME)

re: fclean all
