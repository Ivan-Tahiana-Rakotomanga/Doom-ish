/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_img.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fxu-lin <fxu-lin@student.42antananarivo.m  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 10:28:45 by fxu-lin           #+#    #+#             */
/*   Updated: 2025/06/17 14:25:31 by fxu-lin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MLX_IMG_H
# define MLX_IMG_H

t_mlx *ft_free_mlx(t_mlx *mlx);
void ft_mlx_destroy(t_mlx *mlx);
int ft_close_window(t_mlx *mlx);
void ft_hook(t_mlx *mlx);
int ft_key_press(int code, t_mlx *mlx);
void ft_color_display(char **map, t_mlx *mlx);

#endif
