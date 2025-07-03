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

void	ft_color_display(t_mlx *mlx)
{
	int y;
	int x;
	t_point a;
	char **map;

	y = 0;
	x = 0;
	map = mlx->map;

	while(map[y])
	{
		x = 0;
		while (map[y][x])
		{
			a.x = x;
			a.y = y;
			if(map[y][x] == '1')
				ft_draw_square(a,mlx->side - 1,ft_strdup("0,255,0"),mlx);
			else
				ft_draw_square(a,mlx->side - 1,ft_strdup("255,255,255"),mlx);
			x++;
		}
		y++;
	}
	a.x = mlx->x_player + 1;
	a.y = mlx->y_player;
	ft_draw_square(a,5,ft_strdup("255,0,0"),mlx);



	mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->img, 0, 0);
}
