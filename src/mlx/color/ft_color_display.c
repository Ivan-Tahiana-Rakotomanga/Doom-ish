/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_color_display.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fxu-lin <fxu-lin@student.42antananarivo.m  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 16:06:00 by fxu-lin           #+#    #+#             */
/*   Updated: 2025/08/12 09:03:16 by irakotom         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../../../includes/header.h"

void	ft_display_player(t_mlx *mlx)
{
	t_player	*player;

	player = mlx->player;
	ft_draw_all_rays(player, mlx);
}

void	ft_color_display(t_mlx *mlx)
{	
	ft_draw_ceiling_floor(*mlx);
	ft_display_player(mlx);
	mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->img, 0, 0);
}
