/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hook.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fxu-lin <fxu-lin@student.42antananarivo.m  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 13:09:29 by fxu-lin           #+#    #+#             */
/*   Updated: 2025/08/13 16:50:34 by irakotom         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/header.h"

void	ft_hook(t_mlx *mlx)
{
	mlx_hook(mlx->win, 17, 0, ft_close_window, mlx);
	mlx_hook(mlx->win, 2, 1L << 0, ft_key_press, mlx);
	mlx_hook(mlx->win, 3, 1L << 1, ft_key_release, mlx->player);
	mlx_loop_hook(mlx->mlx, ft_render, mlx);
}
