/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_mlx.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fxu-lin <fxu-lin@student.42antananarivo.m  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 10:02:55 by fxu-lin           #+#    #+#             */
/*   Updated: 2025/06/18 16:08:55 by fxu-lin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/header.h"
#include <stdlib.h>


double ft_pixel_player(int value, t_mlx *mlx)
{
	double half;
	half = (mlx->side / 2);

	return (ft_coordinate_to_pixel((double)value ,mlx->side) + half);
}


void ft_init_player(t_mlx **mlx)
{
	t_player *player;

	player = malloc(sizeof(t_player));
	if(!player)
		return;		
	player->x = ft_pixel_player((*mlx)->x_player, *mlx);
	player->y = ft_pixel_player((*mlx)->y_player, *mlx); 	
	player->angle = 90;
	player->angle_direction = 0;
	player->move_direction = 0;
	player->speed = 10;
	player->angle_speed = 2;
	(*mlx)->player = player;
}




t_mlx	*ft_init_mlx(t_mlx *mlx, char **map)
{
	mlx = malloc(sizeof(t_mlx));
	if (!mlx)
		return (ft_free_mlx(mlx));
	mlx->side = 100;
	mlx->map = map;
	ft_init_size_window(mlx);
	ft_init_key(mlx);
	if (!ft_check_mlx(mlx, "cub3D"))
		return (ft_free_mlx(mlx));
	mlx->x_player = -1;
	mlx->y_player = -1;
	ft_find_start(&mlx->x_player, &mlx->y_player, map);
	ft_init_player(&mlx);

	return (mlx);
}
