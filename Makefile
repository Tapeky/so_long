# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tsadouk <tsadouk@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/03 19:54:19 by tsadouk           #+#    #+#              #
#    Updated: 2023/12/19 14:06:24 by tsadouk          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = test

CC = clang
CFLAGS = -Wall -Werror -Wextra -g  

SRCS =	main.c \
		check_map.c \
		get_map.c \
		put_texture.c \
		GNL/get_next_line.c \
		GNL/get_next_line_utils.c \
		mouvements.c \
		
OBJS = $(SRCS:.c=.o)

LIBFT_SRC = Libft
LIBFT = $(LIBFT_SRC)/libft.a

MLX_SRC = MacroLibX
MLX = $(MLX_SRC)/libmlx.so

all: $(NAME)

$(NAME): $(LIBFT) $(MLX) $(OBJS)
	$(CC) $(CFLAGS) -lSDL2 $(OBJS) -o $(NAME) $(LIBFT) $(MLX)

$(LIBFT):
	make -C $(LIBFT_SRC) -j$(shell nproc)

$(MLX):
	make -C $(MLX_SRC) -j$(shell nproc)

%.o: %.c
	#$(CC) $(CFLAGS) -I ./MacroLibX/includes -I Libft -O3 -c $< -o $@
	$(CC) $(CFLAGS) -I ./MacroLibX/includes -I Libft -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME) $(OBJS_BONUS) libft.so

re: fclean all

.PHONY: clean all re fclean
