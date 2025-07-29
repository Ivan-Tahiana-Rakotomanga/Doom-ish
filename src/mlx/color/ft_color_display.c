/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_color_display.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fxu-lin <fxu-lin@student.42antananarivo.m  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 16:06:00 by fxu-lin           #+#    #+#             */
/*   Updated: 2025/07/23 12:54:52 by irakotom         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../../../includes/header.h"

void	ft_display_player(t_mlx *mlx)
{
	t_player	*player;

	player = mlx->player;
	ft_draw_all_rays(player, mlx);
}

void	ft_draw_ceiling(t_mlx *mlx, char *color)
{
	t_point	start;
	t_point	end;

	start.x = 0;
	start.y = 0;
	end.y = (double)mlx->height / 2;
	end.x = mlx->width;
	ft_draw_rect(start, end, color, mlx);
}

void	ft_draw_floor(t_mlx *mlx, char *color)
{
	t_point	start;
	t_point	end;

	start.x = 0;
	start.y = (double)mlx->height / 2;
	end.y = mlx->height;
	end.x = mlx->width;
	ft_draw_rect(start, end, color, mlx);
}

void	ft_color_display(t_mlx *mlx)
{
	ft_draw_ceiling(mlx, mlx->utils.c);
	ft_draw_floor(mlx, mlx->utils.f);
	ft_display_player(mlx);
	mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->img, 0, 0);
}
