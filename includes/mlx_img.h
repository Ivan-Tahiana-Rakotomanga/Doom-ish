/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_img.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fxu-lin <fxu-lin@student.42antananarivo.m  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 10:28:45 by fxu-lin           #+#    #+#             */
/*   Updated: 2025/06/18 16:07:25 by fxu-lin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MLX_IMG_H
# define MLX_IMG_H

t_mlx	*ft_free_mlx(t_mlx *mlx);
void	ft_mlx_destroy(t_mlx *mlx);
int		ft_close_window(t_mlx *mlx);
void	ft_hook(t_mlx *mlx);
int		ft_key_press(int code, t_mlx *mlx);
void	ft_color_display(t_mlx *mlx);
int		ft_map_width(char **map);
int		ft_map_height(char **map);
void	ft_init_key(t_mlx *mlx);
void	ft_init_size_window(t_mlx *mlx, int width, int height);
int		ft_check_mlx(t_mlx *mlx, char *name);
int		ft_get_limit_x(t_mlx *mlx);
int		ft_get_limit_y(t_mlx *mlx);
void	ft_get_limits_size(int *limit_x, int *limit_y, t_mlx *mlx);
void	ft_add_color_pixels(t_mlx *mlx, char c);
void	ft_put_pixels(t_mlx *mlx, int i, int j);
t_mlx	*ft_init_mlx(t_mlx *mlx, char **map);

#endif
