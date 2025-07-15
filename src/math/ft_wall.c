/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wall.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fxu-lin <fxu-lin@student.42antananarivo.m  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/14 09:49:19 by fxu-lin           #+#    #+#             */
/*   Updated: 2025/07/14 09:49:19 by fxu-lin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/header.h"

int	ft_is_wall(double x_pixel, double y_pixel, t_mlx mlx)
{
	double	side;
	char	**map;
	int		x;
	int		y;

	map = mlx.map;
	side = mlx.side;
	if(!ft_on_screen(x_pixel, y_pixel,mlx))
	{
		printf("Tonga ato %f et %f\n", x_pixel, y_pixel);
		return (1);
	}
	x = ft_pixel_to_coordinate(x_pixel, side);
	y = ft_pixel_to_coordinate(y_pixel, side);
	if (map[y][x] == '1')
		return (1);
	return (0);
}

double ft_get_height_wall(t_player player,t_mlx mlx, double distance, double wall_height)
{
	double throw_distance; 

	throw_distance = ft_throw_distance(mlx.width , player.fov); 
	
	if(distance == 0.0)
		return (0);
	return ((throw_distance/ distance) * wall_height);
}
