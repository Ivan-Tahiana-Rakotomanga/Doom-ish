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

int ft_ray_direction(double ray_angle);
int ft_horizontal_inter_y(t_mlx *mlx, double ray_angle, double player_pos_y);
int ft_horizontal_inter_x(t_mlx *mlx, double ray_angle, double player_pos_x, double player_pos_y);
int ft_check_wall(t_mlx *mlx, double horizontal_pos_x, double horizontal_pos_y);
double ft_coordinate_to_pixel(double value,double side);
double ft_pixel_to_coordinate(double value, double side);
t_point	ft_increment_dda(t_point a, t_point b);


#endif
