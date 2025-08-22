/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wall.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fxu-lin <fxu-lin@student.42antananarivo.m  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/14 09:49:19 by fxu-lin           #+#    #+#             */
/*   Updated: 2025/07/16 10:22:05 by irakotom         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/header.h"

int	ft_format_value(int value, int max)
{
	if (value < 0)
		return (0);
	else if (max <= value)
		return (max - 1);
	return (value);
}

int	ft_is_wall(double x_pixel, double y_pixel, t_mlx mlx)
{
	double	side;
	char	**map;
	int		x;
	int		y;

	map = mlx.map;
	side = mlx.side;
	x = ft_pixel_to_coordinate(x_pixel, side);
	y = ft_pixel_to_coordinate(y_pixel, side);
	x = ft_format_value(x, ft_strlen(map[0]));
	y = ft_format_value(y, ft_strs_len(map));
	if (map[y][x] == '1' || map[y][x] == ' ')
		return (1);
	return (0);
}

double	ft_get_height_wall(t_player player, t_mlx mlx, double distance,
		double wall_height)
{
	double	throw_distance;

	throw_distance = ft_throw_distance(mlx.width, player.fov);
	if (distance == 0.0)
		return (0);
	return ((wall_height / distance) * throw_distance);
}
