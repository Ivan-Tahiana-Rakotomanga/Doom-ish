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
			a.x = ft_coordinate_to_pixel((double)x,mlx->side);
			a.y = ft_coordinate_to_pixel((double)y,mlx->side);
			if(map[y][x] == '1')
				ft_draw_square(a,mlx->side - 1,ft_strdup("0,255,0"),mlx);
			else
				ft_draw_square(a,mlx->side - 1,ft_strdup("255,255,255"),mlx);
			x++;
		}
		y++;
	}		
		a.x = ft_coordinate_to_pixel((double)mlx->x_player,mlx->side) + (mlx->side / 2);
		a.y = ft_coordinate_to_pixel((double)mlx->y_player,mlx->side) + (mlx->side / 2);
		ft_draw_square(a,5,ft_strdup("255,0,0"),mlx);

	    t_point end;
	    a.x = a.x + 1.0;
	    a.y = a.y + 1.0;

	    double degree = -90;

	    double x_cos = cos(ft_degree_to_radian(degree))  * 50 ;
	    double y_sin = sin(ft_degree_to_radian(degree))  * 50;
	    end.x =  a.x + x_cos ;
	    end.y =  a.y + y_sin ; 


	    printf("Ito ilay x %f   y  %f\n", a.x, a.y);
	    printf("Ito ilay x %f   y  %f\n", end.x, end.y);



	    ft_draw_line(a,end,ft_strdup("0,0,255"),mlx);


		mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->img, 0, 0);
}
