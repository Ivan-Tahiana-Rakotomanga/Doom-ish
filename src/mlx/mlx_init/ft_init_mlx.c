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

double	ft_init_utils(t_mlx *mlx, t_utils utils, char **map)
{
	double	angle;
	char	c;

	mlx->x_player = -1;
	mlx->y_player = -1;
	angle = 0.0;
	c = ft_find_start(&mlx->y_player, &mlx->x_player, map);
	angle = ft_angle_orientation(c);
	mlx->utils = utils;
	mlx->no = ft_get_img(utils.no, mlx->mlx);
	mlx->so = ft_get_img(utils.so, mlx->mlx);
	mlx->ea = ft_get_img(utils.ea, mlx->mlx);
	mlx->wo = ft_get_img(utils.we, mlx->mlx);
	return (angle);
}

t_mlx	*ft_init_mlx(t_mlx *mlx, char **map, t_utils utils)
{
	double	angle;

	angle = 0.0;
	mlx = malloc(sizeof(t_mlx));
	if (!mlx)
		return (ft_free_mlx(mlx));
	ft_memset(mlx, 0, sizeof(t_mlx));
	mlx->side = 32;
	mlx->map = map;
	mlx->width = 800;
	mlx->height = 800;
	mlx->width_one_wall = 1;
	if (!ft_check_mlx(mlx, "doomISH"))
		return (ft_free_mlx(mlx));
	angle = ft_init_utils(mlx, utils, map);
	if (!ft_init_player(&mlx, angle))
		return (ft_free_mlx(mlx));
	return (mlx);
}
