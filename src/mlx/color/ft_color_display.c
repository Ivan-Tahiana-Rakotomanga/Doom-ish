/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_color_display.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fxu-lin <fxu-lin@student.42antananarivo.m  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 16:06:00 by fxu-lin           #+#    #+#             */
/*   Updated: 2025/07/16 11:22:15 by irakotom         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../../../includes/header.h"

void	ft_display_player(t_mlx *mlx)
{
	t_player	*player;

	player = mlx->player;
	ft_draw_all_rays(player, mlx);
}

void ft_draw_ceiling(t_mlx *mlx, char *color)
{
	t_point start;
	t_point end;
	
	start.x = 0;
	start.y = 0;
	end.y = (double)mlx->height / 2;
	end.x = mlx->width;
	ft_draw_rect(start,end,color,mlx);
}

void ft_draw_floor(t_mlx *mlx, char *color)
{
	t_point start;
	t_point end;
	
	start.x = 0;
	start.y = (double)mlx->height / 2;
	end.y = mlx->height; 
	end.x = mlx->width;
	ft_draw_rect(start,end,color,mlx);
}

void	ft_color_display(t_mlx *mlx)
{
	/*t_point	a;*/
	/*char	**map;*/
	/*int		x;*/
	/*int		y;*/
	/**/
	/*y = 0;*/
	/*x = 0;*/
	/*map = mlx->map;*/
	/*while (map[y])*/
	/*{*/
	/*	x = 0;*/
	/*	while (map[y][x])*/
	/*	{*/
	/*		a.x = ft_coordinate_to_pixel((double)x, mlx->side);*/
	/*		a.y = ft_coordinate_to_pixel((double)y, mlx->side);*/
	/*		if (map[y][x] == '1')*/
	/*			ft_draw_square(a, mlx->side - 1, ft_strdup("0,255,0"), mlx);*/
	/*		else*/
	/*			ft_draw_square(a, mlx->side , ft_strdup("255,255,255"), mlx);*/
	/*		x++;*/
	/*	}*/
	/*	y++;*/
	/*}*/
	ft_draw_ceiling(mlx, ft_strdup("47, 255, 255"));
	ft_draw_floor(mlx, ft_strdup("238, 201, 125"));


	ft_display_player(mlx);
	mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->img, 0, 0);
}
