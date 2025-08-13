/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hook.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fxu-lin <fxu-lin@student.42antananarivo.m  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 13:09:29 by fxu-lin           #+#    #+#             */
/*   Updated: 2025/06/17 13:09:29 by fxu-lin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/header.h"

void	ft_hook(t_mlx *mlx)
{
	mlx_hook(mlx->win, 17, 0, ft_close_window, mlx);
	mlx_hook(mlx->win, 2, 1L << 0, ft_key_press, mlx->player);
	mlx_loop_hook(mlx->mlx, ft_render, mlx);
}
