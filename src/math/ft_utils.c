/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fxu-lin <fxu-lin@student.42antananarivo.m  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/03 16:44:43 by fxu-lin           #+#    #+#             */
/*   Updated: 2025/07/03 16:44:43 by fxu-lin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/header.h"

double	ft_convert_angle(int angle)
{
	double	res;

	res = angle * (M_PI / 180);
	return (res);
}

double	ft_normalize_angle(double angle)
{
	angle = fmod(angle, 2 * M_PI);
	if (angle < 0)
		angle = (2 * M_PI) + angle;
	return (angle);
}

int	ft_ray_direction(double ray_angle)
{
	if (ray_angle > 0 && ray_angle < M_PI)
		return (-1);
	else if (ray_angle < 0 || ray_angle > M_PI)
		return (1);
	else if (ray_angle < 0.5 * M_PI || ray_angle > 1.5 * M_PI)
		return (2);
	else if (ray_angle > 0.5 * M_PI && ray_angle < 1.5 * M_PI)
		return (-2);
	return (0);
}

int	ft_convert_pixel(t_mlx *mlx, int player_pos)
{
	int	res;

	res = player_pos / mlx->side;
	return (res);
}
