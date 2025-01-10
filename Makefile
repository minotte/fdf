# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nminotte <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/22 16:47:18 by nminotte          #+#    #+#              #
#    Updated: 2023/01/31 16:53:16 by nminotte         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := fdf

SRC = ./main.c \
	  ./parsing.c \
	  ./fdf_mlx_win.c \
	  digital_diff_analyzer.c \
	  color.c \
	  img_cent.c \
	  rotation.c \
	  move_zoom.c \
	  xy_to_print.c \
	  iso.c
	
OBJS = $(SRC:.c=.o)

CFLAGS = -Wall -Wextra -Werror -I/usr/include -Imlx_linux -O0 -g

MINILIBX = -lm -lX11 -lXext -lz -Lminilibx-linux

LIBFT = ./libft/libft.a

CC = clang

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

all : $(LIBFT) $(MINILIBX) $(NAME) 

$(MINILIBX):
	make -C ./minilibx-linux

$(LIBFT):
	make -C ./libft

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -Lminilibx-linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz ./libft/libft.a -o $(NAME)


	
clean :
	@make clean -C ./libft
	@rm -rf $(OBJS)
	
fclean : clean
	@make fclean -C ./libft
	@rm -rf $(NAME)

re : fclean all

.PHONY: all clean re fclean
