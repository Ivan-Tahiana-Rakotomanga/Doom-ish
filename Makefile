# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: irakotom <irakotom@student.42antananarivo  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/06/04 12:56:49 by irakotom          #+#    #+#              #
#    Updated: 2025/06/18 16:07:53 by fxu-lin          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3D 
SRC =  src/handle_error/file/ft_valid_extension.c \
		src/handle_error/file/ft_utils_check_file.c \
		src/handle_error/file/ft_many_args_line.c \
		src/handle_error/file/ft_check_file.c \
		src/handle_error/file/ft_valid_file.c \
		src/handle_error/file/ft_is_valid_path.c \
		src/handle_error/color/ft_valid_color.c \
		src/handle_error/color/ft_is_duplicate_color.c \
		src/handle_error/color/ft_check_colors.c \
		src/handle_error/id/ft_index_id.c \
		src/handle_error/map/ft_format_map_is_valid.c \
		src/handle_error/map/ft_check_map.c \
		src/handle_error/map/ft_flood_fill.c \
		src/handle_error/map/ft_characters_valid_map.c \
		src/handle_error/map/ft_list_map.c \
		src/handle_error/map/ft_utils_list_map.c \
		src/handle_error/map/ft_map_to_strs.c \
		src/mlx/action/ft_close_window.c \
		src/mlx/action/ft_hook.c \
		src/mlx/action/ft_key_press.c \
		src/mlx/action/ft_mlx_destroy.c \
		src/mlx/color/ft_color_display.c \
		src/mlx/color/ft_convert_color.c \
		src/mlx/color/ft_put_pixels.c \
		src/mlx/color/ft_get_limits_size.c \
		src/mlx/color/ft_utils.c \
		src/mlx/color/ft_add_color_pixels.c \
		src/mlx/mlx_init/ft_free_mlx.c \
		src/mlx/mlx_init/ft_init_mlx.c \
		src/mlx/mlx_init/ft_check_mlx.c \
		src/mlx/mlx_init/ft_init_key.c \
		src/mlx/mlx_init/ft_init_window.c \
		src/utils/ft_strcmp.c \
		src/utils/ft_free.c \
		src/utils/ft_get_next_line.c \
		src/utils/ft_space.c \
		src/utils/ft_is_empty_str.c \
		src/utils/ft_is_valid_number.c \
		src/utils/ft_strs_len.c \
        src/main.c 

OBJ = $(SRC:.c=.o)
CC = gcc
CFLAGS = -Wall -Wextra -Werror -I./includes -g
MLX = minilibx-linux/libmlx.a
INC = -I minilibx-linux
MLX_FLAG = -Lminilibx-linux -lmlx -lm -lX11 -lXext
LIBFT_DIR = ./libft
LIBFT = $(LIBFT_DIR)/libft.a 

all: $(NAME)

$(NAME): $(OBJ) $(LIBFT)
	$(CC) $(CFLAGS) $(INC) $^ $(MLX) $(MLX_FLAG) -o $@

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

