/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_window.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fxu-lin <fxu-lin@student.42antananarivo.m  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 16:01:51 by fxu-lin           #+#    #+#             */
/*   Updated: 2025/06/18 16:01:51 by fxu-lin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/header.h"

void	ft_init_size_window(t_mlx *mlx)
{
	double	width;
	double	height;
	double	res;

	width = ft_strlen(mlx->map[0]) * mlx->side;
	height = ft_strs_len(mlx->map) * mlx->side;
	res = fmax(width, height);
	mlx->width = res;
	mlx->height = res;
}
