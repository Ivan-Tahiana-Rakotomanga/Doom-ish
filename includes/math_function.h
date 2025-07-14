/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math_function.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fxu-lin <fxu-lin@student.42antananarivo.m  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/04 10:24:33 by fxu-lin           #+#    #+#             */
/*   Updated: 2025/07/04 10:25:48 by fxu-lin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATH_FUNCTION_H
# define MATH_FUNCTION_H

int		ft_ray_direction(double ray_angle);
int		ft_horizontal_inter_y(t_mlx *mlx, double ray_angle,
			double player_pos_y);
int		ft_horizontal_inter_x(t_mlx *mlx, double ray_angle, double player_pos_x,
			double player_pos_y);
int		ft_check_wall(t_mlx *mlx, double horizontal_pos_x,
			double horizontal_pos_y);
double	ft_coordinate_to_pixel(double value, double side);
double	ft_pixel_to_coordinate(double value, double side);
t_point	ft_increment_dda(t_point a, t_point b);
double	ft_degree_to_radian(double degree);
double	ft_first_hit_hy(double y_pixel, double side, double angle);
double	ft_first_hit_hx(t_player player, double angle, double y_pixel);
double	ft_first_hit_vx(double x_pixel, double side, double angle);
double	ft_first_hit_vy(t_player player, double angle, double x_pixel);
int		ft_is_wall(double x_pixel, double y_pixel, t_mlx mlx);
t_point	ft_end_hit_h(double angle, t_mlx mlx, double y_pixel);
t_point	ft_end_hit_v(double angle, t_mlx mlx, double x_pixel);
t_point	ft_get_end(double angle, t_mlx mlx, double y_pixel, double x_pixel);
double	ft_limit_angle(double angle);
double	ft_get_distance(t_point end, t_player player);
int	ft_on_screen(double x, double y, t_mlx mlx);
int	ft_on_screen(double x, double y, t_mlx mlx);

#endif
