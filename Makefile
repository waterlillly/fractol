# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lbaumeis <lbaumeis@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/17 14:08:48 by lbaumeis          #+#    #+#              #
#    Updated: 2024/06/21 19:05:25 by lbaumeis         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFILES = main.c init.c complex.c render.c mlx_events.c julia.c
OBJ = $(CFILES:.c=.o)
%.o: %.c
	$(CC) -Wall -Wextra -Werror -g -I/usr/include -Imlx_linux -O3 -c $< -o $@
P_NAME = fractol

all: $(P_NAME)

$(P_NAME): $(OBJ)
	($(MAKE) -C ./libft)
	$(CC) $(OBJ) ./libft/libft.a -lmlx -lXext -lX11 -lm -lz -o $(P_NAME)

clean:
	($(MAKE) -C ./libft clean)
	rm -f $(OBJ)

fclean: clean
	($(MAKE) -C ./libft fclean)
	rm -f $(P_NAME)

re: fclean all

.PHONY: all clean fclean re
