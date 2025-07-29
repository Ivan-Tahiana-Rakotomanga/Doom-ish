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
	double width;
	double height;
	width = ft_strlen(mlx->map[0]);
	height = ft_strs_len(mlx->map);
	
	mlx->width = width * mlx->side;
	mlx->height = height * mlx->side;
}
