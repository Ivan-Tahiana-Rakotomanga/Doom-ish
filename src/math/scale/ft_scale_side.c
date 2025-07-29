/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_scale_side.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fxu-lin <fxu-lin@student.42antananarivo.m  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/29 15:37:38 by fxu-lin           #+#    #+#             */
/*   Updated: 2025/07/29 15:37:40 by fxu-lin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/header.h"

void	ft_scale_side(char **map, t_mlx *mlx)
{
	double	width;
	double	height;
	double	max;

	width = ft_strlen(map[0]);
	height = ft_strs_len(map);
	max = fmax(width, height);
	if (max < 600)
		mlx->side = (int)ceil(600 / max);
	else
		mlx->side = (int)ceil(max / 600);
}
