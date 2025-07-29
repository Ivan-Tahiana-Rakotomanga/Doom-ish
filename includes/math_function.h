/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math_function.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fxu-lin <fxu-lin@student.42antananarivo.m  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/04 10:24:33 by fxu-lin           #+#    #+#             */
/*   Updated: 2025/07/23 12:55:12 by irakotom         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATH_FUNCTION_H
# define MATH_FUNCTION_H

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
t_point	ft_get_end(double angle, t_mlx mlx, t_point pixel, int *h_v);
double	ft_limit_angle(double angle);
double	ft_get_distance(t_point end, t_player player);
int		ft_on_screen(double x, double y, t_mlx mlx);
int		ft_on_screen(double x, double y, t_mlx mlx);
double	ft_throw_distance(double width_screen, double angle_fov);
double	ft_get_height_wall(t_player player, t_mlx mlx, double distance,
			double wall_height);
double	ft_rules_of_three(double value, double ref_in, double ref_out);
t_img	ft_get_img(char *filename, void *mlx_ptr);
double	ft_orientation(int h_v, double angle);
double	ft_get_x_text(t_point end, double side, int orient);
void	ft_scale_side(char **map, t_mlx *mlx);
double	ft_angle_orientation(char c);
#endif
