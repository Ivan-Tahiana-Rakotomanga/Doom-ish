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

t_mlx	*ft_init_mlx(t_mlx *mlx, char **map)
{
	mlx = malloc(sizeof(t_mlx));
	if (!mlx)
		return (ft_free_mlx(mlx));
	ft_init_size_window(mlx, 800, 600);
	ft_init_key(mlx);
	if (!ft_check_mlx(mlx, "cub3D"))
		return (ft_free_mlx(mlx));
	mlx->map = map;
	return (mlx);
}


