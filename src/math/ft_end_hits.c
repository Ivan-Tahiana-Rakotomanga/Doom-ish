/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_end_hits.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fxu-lin <fxu-lin@student.42antananarivo.m  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/14 09:49:04 by fxu-lin           #+#    #+#             */
/*   Updated: 2025/07/16 10:54:10 by irakotom         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/header.h"

double	ft_get_yxa(double angle, double side, int index)
{
	if (index == 1)
	{
		if (angle < 180)
			return (side);
		return (-side);
	}
	else
	{
		if (90 <= angle && angle <= 270)
			return (-side);
		else
			return (side);
	}
}

t_point	ft_end_hit_h(double angle, t_mlx mlx, double y_pixel)
{
	t_point		end;
	double		ya;
	double		xa;
	t_player	*player;

	player = mlx.player;
	end.y = ft_first_hit_hy(y_pixel, mlx.side, angle);
	end.x = ft_first_hit_hx(*player, angle, end.y);
	if (ft_is_wall(end.x, end.y, mlx))
		return (end);
	ya = ft_get_yxa(angle, mlx.side, 1);
	xa = ya / tan(ft_degree_to_radian(angle));


	while (!ft_is_wall(end.x, end.y, mlx))
	{
		end.x = end.x + xa;
		end.y = end.y + ya;
	}
	return (end);
}

t_point	ft_end_hit_v(double angle, t_mlx mlx, double x_pixel)
{
	t_point		end;
	double		ya;
	double		xa;
	t_player	*player;

	player = mlx.player;
	end.x = ft_first_hit_vx(x_pixel, mlx.side, angle);
	end.y = ft_first_hit_vy(*player, angle, end.x);
	if (ft_is_wall(end.x, end.y, mlx))
		return (end);
	xa = ft_get_yxa(angle, mlx.side, 2);
	ya = xa * tan(ft_degree_to_radian(angle));
	while (!ft_is_wall(end.x, end.y, mlx))
	{
		end.x = end.x + xa;
		end.y = end.y + ya;
	}
	return (end);
}

t_point	ft_get_end(double angle, t_mlx mlx, t_point pixel, int *h_v)
{
	t_point		v;
	t_point		h;
	double		d_h;
	double		d_v;
	t_player	*player;

	player = mlx.player;
	h = ft_end_hit_h(angle, mlx, pixel.y);
	v = ft_end_hit_v(angle, mlx, pixel.x);
	d_h = ft_get_distance(h, *player);
	d_v = ft_get_distance(v, *player);
	if (d_h < d_v)
	{
		*h_v = 1;
		return (h);
	}
	else
	{
		*h_v = 2;
		return (v);
	}
}
