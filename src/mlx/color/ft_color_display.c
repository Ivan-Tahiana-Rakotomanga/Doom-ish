/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_color_display.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fxu-lin <fxu-lin@student.42antananarivo.m  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 16:06:00 by fxu-lin           #+#    #+#             */
/*   Updated: 2025/07/02 18:58:00 by irakotom         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../../../includes/header.h"

void	ft_display_player(t_mlx *mlx)
{
	t_point		a;
	t_player	*player;

	player = mlx->player;
	a.x = player->x;
	a.y = player->y;
	ft_draw_square(a, 5, ft_strdup("255,0,0"), mlx);
	ft_draw_all_rays(player, mlx);
}

void	ft_color_display(t_mlx *mlx)
{
	int		y;
	int		x;
	t_point	a;
	char	**map;

	y = 0;
	x = 0;
	map = mlx->map;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			a.x = ft_coordinate_to_pixel((double)x, mlx->side);
			a.y = ft_coordinate_to_pixel((double)y, mlx->side);
			if (map[y][x] == '1')
				ft_draw_square(a, mlx->side - 1, ft_strdup("0,255,0"), mlx);
			else
				ft_draw_square(a, mlx->side - 1, ft_strdup("255,255,255"), mlx);
			x++;
		}
		y++;
	}
	ft_display_player(mlx);
	mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->img, 0, 0);
}
