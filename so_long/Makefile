# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tpiras <tpiras@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/24 14:09:36 by tpiras            #+#    #+#              #
#    Updated: 2023/04/04 15:18:06 by tpiras           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

MINILIBX_PATH = ../mlx

MINILIBX = $(MINILIBX_PATH)/libmlx.a

LIBFT_PATH = ./libft

LIBFT = $(LIBFT_PATH)/libft.a

NAME = so_long

HEADER = $(NAME:.a=.h)

SOURCES = so_long.c \
map.c \
game.c \
control.c \
movement.c \
enemy_movement.c \
death_animation.c \
door_animation.c \
libft/ft_split.c \
libft/ft_strlen.c \
libft/ft_substr.c \
libft/ft_itoa.c \

OBJ = $(SOURCES:.c=.o)

LIBC = ar rcs

MLX = ./libmlx.dylib

CC = gcc

RM = rm -f

CFLAGS = -Wall -Werror -Wextra -Imlx -g

all: $(LIBFT) $(NAME) 

$(NAME): $(OBJ) $(LIBFT) $(MINILIBX)
	$(CC) $(OBJ) $(LIBFT) $(MINILIBX) -lmlx -framework OpenGL -framework AppKit -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(LIBFT):
		@make -C $(LIBFT_PATH)

$(MINILIBX):
		@(make -C $(MINILIBX_PATH)) 2> /dev/null

clean:
		@$(RM) $(OBJ)
		@make clean -C $(LIBFT_PATH)
		@make clean -C $(MINILIBX_PATH)

fclean: clean
		@$(RM) $(NAME)
		@$(RM) $(LIBFT)
		@$(RM) $(MINILIBX)

re: fclean all

.PHONY: all clean fclean re