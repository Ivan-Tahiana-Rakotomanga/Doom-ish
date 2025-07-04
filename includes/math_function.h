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

#endif
