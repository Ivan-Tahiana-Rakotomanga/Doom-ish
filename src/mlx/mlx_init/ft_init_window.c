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

	mlx->width = mlx->side * ft_strlen(mlx->map[0]);
	mlx->height = mlx->side * ft_strs_len(mlx->map);
}
