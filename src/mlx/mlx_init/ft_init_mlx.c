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

	half = ((double)mlx->side / 2);
	return (ft_coordinate_to_pixel((double)value, mlx->side) + half);
}

int	ft_init_player(t_mlx **mlx)
{
	t_player	*player;

	player = malloc(sizeof(t_player));
	if (!player)
		return (0);
	ft_memset(player, 0, sizeof(t_player));
	player->x = ft_pixel_player((*mlx)->x_player, *mlx);
	player->y = ft_pixel_player((*mlx)->y_player, *mlx);
	player->angle_direction = 0;
	player->move_direction = 0;
	player->fov = 60;
	player->nb_rays = (*mlx)->width / (*mlx)->width_one_wall;
	player->speed = 10;
	player->angle_speed = 2;
	(*mlx)->player = player;
	return (1);
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
	char	c;

	mlx = malloc(sizeof(t_mlx));
	if (!mlx)
		return (ft_free_mlx(mlx));
	ft_memset(mlx, 0, sizeof(t_mlx));
	ft_scale_side(map, mlx);
	mlx->map = map;
	mlx->width_one_wall = 4;
	if (!mlx->map || !mlx->map[0])
		return (ft_free_mlx(mlx));
	ft_init_size_window(mlx);
	if (mlx->width <= 0 || mlx->height <= 0)
		return (ft_free_mlx(mlx));
	if (!ft_check_mlx(mlx, "cub3D"))
		return (ft_free_mlx(mlx));
	ft_init_key(mlx);
	ft_init_textures(mlx, utils);
	mlx->x_player = -1;
	mlx->y_player = -1;
	c = ft_find_start(&mlx->x_player, &mlx->y_player, map);
	if (!ft_init_player(&mlx))
	{
		return (ft_free_mlx(mlx));
	}
	mlx->player->angle = ft_angle_orientation(c);
	return (mlx);
}
