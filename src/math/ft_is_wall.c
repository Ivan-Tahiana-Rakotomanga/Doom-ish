/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_wall.c                                       :+:      :+:    :+:   */
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
	if (x_pixel <= 0 || mlx.width <= x_pixel || y_pixel <= 0
		|| mlx.height <= y_pixel)
		return (1);
	x = ft_pixel_to_coordinate(x_pixel, side);
	y = ft_pixel_to_coordinate(y_pixel, side);
	if (map[y][x] == '1')
		return (1);
	return (0);
}
