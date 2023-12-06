# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tsadouk <tsadouk@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/03 19:54:19 by tsadouk           #+#    #+#              #
#    Updated: 2023/12/06 14:31:06 by tsadouk          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = clang

CFLAGS = -Wall -Werror -Wextra 

SRCS = main.c \

OBJS = $(SRCS:.c=.o)

NAME = test

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -Lmlx -lmlx_Linux -L/usr/lib -lXext -lX11 -lm -lz -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -Wall -Wextra -Werror -I/usr/include -Imlx -O3 -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME) $(OBJS_BONUS) libft.so

re: fclean all

.PHONY: clean all re fclean
