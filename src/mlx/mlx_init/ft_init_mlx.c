/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_mlx.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fxu-lin <fxu-lin@student.42antananarivo.m  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 10:02:55 by fxu-lin           #+#    #+#             */
/*   Updated: 2025/07/16 11:28:28 by irakotom         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/header.h"
#include <stdlib.h>

double	ft_pixel_player(int value, t_mlx *mlx)
{
	double	half;

	half = (mlx->side / 2);
	return (ft_coordinate_to_pixel((double)value, mlx->side) + half);
}

void	ft_init_player(t_mlx **mlx)
{
	t_player	*player;

	player = malloc(sizeof(t_player));
	if (!player)
		return ;
	player->x = ft_pixel_player((*mlx)->x_player, *mlx);
	player->y = ft_pixel_player((*mlx)->y_player, *mlx);
	player->angle = 0;
	player->angle_direction = 0;
	player->move_direction = 0;
	player->fov = 60;
	player->nb_rays = (*mlx)->width / (*mlx)->width_one_wall;
	player->speed = 10;
	player->angle_speed = 2;
	(*mlx)->player = player;
}

void	ft_init_textures(t_mlx *mlx, t_utils utils)
{
	mlx->utils = utils;
	mlx->no = ft_get_img(utils.no, mlx->mlx);
	mlx->so = ft_get_img(utils.so, mlx->mlx);
	mlx->ea = ft_get_img(utils.ea, mlx->mlx);
	mlx->wo = ft_get_img(utils.we, mlx->mlx);
}

t_mlx	*ft_init_mlx(t_mlx *mlx, char **map, t_utils utils)
{
	mlx = malloc(sizeof(t_mlx));
	if (!mlx)
		return (ft_free_mlx(mlx));
	mlx->side = 32;
	mlx->map = map;
	mlx->width_one_wall = 1;
	ft_init_size_window(mlx);
	ft_init_key(mlx);
	if (!ft_check_mlx(mlx, "cub3D"))
		return (ft_free_mlx(mlx));
	ft_init_textures(mlx, utils);
	mlx->x_player = -1;
	mlx->y_player = -1;
	ft_find_start(&mlx->x_player, &mlx->y_player, map);
	ft_init_player(&mlx);
	return (mlx);
}
