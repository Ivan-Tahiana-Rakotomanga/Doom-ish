# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: irakotom <irakotom@student.42antananarivo  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/06/04 12:56:49 by irakotom          #+#    #+#              #
#    Updated: 2025/06/04 12:56:49 by irakotom         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3D 
SRC = src/handle_error/ft_valid_arg_count.c \
			src/handle_error/file/ft_valid_extension.c \
			src/handle_error/file/ft_valid_file.c \
			src/handle_error/color/ft_valid_color.c \
			src/handle_error/color/ft_is_duplicate_color.c \
			src/handle_error/map/ft_format_map_is_valid.c \
      src/main.c 

OBJ = $(SRC:.c=.o)
CC = gcc
CFLAGS = -Wall -Wextra -Werror -I./includes -g
LDFLAGS = -lreadline
LIBFT_DIR = ./libft
LIBFT = $(LIBFT_DIR)/libft.a 

all: $(NAME)

$(NAME): $(OBJ) $(LIBFT)
	$(CC) $(CFLAGS) $^ $(LDFLAGS) -o $@

$(LIBFT):
	make -C $(LIBFT_DIR)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)
	make clean -C $(LIBFT_DIR)

fclean: clean
	rm -f $(NAME)
	make fclean -C $(LIBFT_DIR)

re: fclean all

.PHONY: all clean fclean re

