# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: irakotom <irakotom@student.42antananarivo  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/06/04 12:56:49 by irakotom          #+#    #+#              #
#    Updated: 2025/07/24 17:29:39 by irakotom         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3D 
SRC =  src/handle_error/file/ft_valid_extension.c \
		src/handle_error/file/ft_utils_check_file.c \
		src/handle_error/file/ft_many_args_line.c \
		src/handle_error/file/ft_check_file.c \
		src/handle_error/file/ft_valid_file.c \
		src/handle_error/file/ft_is_valid_path.c \
		src/handle_error/file/ft_check_xpm.c \
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
		src/info/ft_get_info.c \
		src/math/ft_dda.c \
		src/math/ft_orientation.c \
		src/math/ft_get_x_text.c \
		src/math/ft_throw_distance.c \
		src/math/ft_on_screen.c \
		src/math/ft_get_distance.c \
		src/math/ft_wall.c \
		src/math/ft_first_hit.c \
		src/math/ft_end_hits.c \
		src/math/ft_degree_to_radian.c \
		src/math/scale/ft_scale.c \
		src/math/scale/ft_rules_of_three.c \
		src/math/ft_utils.c \
		src/mlx/action/ft_close_window.c \
		src/mlx/action/ft_move_player.c \
		src/mlx/action/ft_hook.c \
		src/mlx/action/ft_key_press.c \
		src/mlx/action/ft_mlx_destroy.c \
		src/mlx/color/ft_color_display.c \
		src/mlx/color/ft_convert_color.c \
		src/mlx/color/ft_utils.c \
		src/mlx/color/ft_add_color_pixels.c \
		src/mlx/color/ft_get_address.c \
		src/mlx/draw/ft_draw_rect.c \
		src/mlx/draw/ft_draw_wall.c \
		src/mlx/draw/ft_draw_square.c \
		src/mlx/draw/ft_draw_all_rays.c \
		src/mlx/draw/ft_draw_line.c \
		src/mlx/mlx_init/ft_free_mlx.c \
		src/mlx/mlx_init/ft_init_mlx.c \
		src/mlx/mlx_init/ft_check_mlx.c \
		src/mlx/mlx_init/ft_init_key.c \
		src/mlx/mlx_init/ft_init_window.c \
		src/mlx/texture/ft_set_img.c \
		src/mlx/texture/ft_get_new_y.c \
		src/mlx/texture/ft_draw_rect_textures.c \
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
