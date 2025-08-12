/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_img.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fxu-lin <fxu-lin@student.42antananarivo.m  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 10:28:45 by fxu-lin           #+#    #+#             */
/*   Updated: 2025/08/12 09:02:37 by irakotom         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MLX_IMG_H
# define MLX_IMG_H

# include "all_struct.h"
t_mlx	*ft_free_mlx(t_mlx *mlx);
void	ft_mlx_destroy(t_mlx *mlx);
int		ft_close_window(t_mlx *mlx);
void	ft_hook(t_mlx *mlx);
int		ft_key_press(int code, t_mlx *mlx);
void	ft_color_display(t_mlx *mlx);
int		ft_map_width(char **map);
int		ft_map_height(char **map);
void	ft_init_key(t_mlx *mlx);
void	ft_init_size_window(t_mlx *mlx);
int		ft_check_mlx(t_mlx *mlx, char *name);
int		ft_get_limit_x(t_mlx *mlx);
int		ft_get_limit_y(t_mlx *mlx);
void	ft_get_limits_size(int *limit_x, int *limit_y, t_mlx *mlx);
void	ft_add_color_pixels(t_mlx *mlx, int i, int j);
void	ft_put_pixels(t_mlx *mlx, int i, int j);
t_mlx	*ft_init_mlx(t_mlx *mlx, char **map, t_utils utils);
int		ft_convert_color(char *color);
char	*ft_get_address(int x, int y, t_mlx *mlx);
void	ft_draw_square(t_point pixel, int size, char *color, t_mlx *mlx);
void	ft_draw_line(t_point start, t_point end, char *color, t_mlx *mlx);
void	ft_draw_all_rays(t_player *player, t_mlx *mlx);
void	ft_draw_rect(t_point a, t_point b, char *color, t_mlx *mlx);
void	ft_draw_wall(int i, double distance, t_mlx mlx,
			double *dst_text_orient);
int ft_move_of_player(int code, t_player *player, t_mlx mlx);
void	ft_draw_rect_textures(t_point a, t_point b, t_mlx mlx,
			double *dst_orient);
int		ft_get_new_y(double value, double height_wall, double height_img);
int		ft_init_player(t_mlx **mlx, double angle);
void    ft_draw_ceiling_floor(t_mlx mlx);

#endif
