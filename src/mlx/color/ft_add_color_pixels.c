/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_add_color_pixels.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fxu-lin <fxu-lin@student.42antananarivo.m  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/14 09:50:05 by fxu-lin           #+#    #+#             */
/*   Updated: 2025/07/14 09:50:05 by fxu-lin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/header.h"

void	ft_add_color_pixels(t_mlx *mlx, int i, int j)
{
	char	**map;

	map = mlx->map;
	if (mlx->x_player == i && mlx->y_player == j)
		mlx->color = ft_convert_color("0,0,255");
	else if (map[i][j] == '1')
		mlx->color = ft_convert_color("255,0,0");
	else
		mlx->color = ft_convert_color("0,255,0");
}
