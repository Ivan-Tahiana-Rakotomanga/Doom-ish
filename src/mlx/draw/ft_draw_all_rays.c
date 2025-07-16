/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw_all_rays.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fxu-lin <fxu-lin@student.42antananarivo.m  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/14 09:50:33 by fxu-lin           #+#    #+#             */
/*   Updated: 2025/07/16 11:23:25 by irakotom         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/header.h"

double	ft_draw_ray(double angle, t_player player, t_mlx mlx, int *h_v)
{
	t_point	end;
	t_point	pixel;
	double	res;
	/*t_point	a;*/

	pixel.x = player.x;
	pixel.y = player.y;
	res = 0.0;
	end = ft_get_end(angle, mlx, pixel, h_v);
	/*a.x = player.x;*/
	/*a.y = player.y;*/
	/*ft_draw_line(a, end, ft_strdup("255,0,255"), &mlx);*/
	res = ft_get_distance(end, player)
		* cos(ft_degree_to_radian(fmod(player.angle - angle, 360)));
	return (res);
}

void	ft_loop_wall(double start_angle, double nbr_rays, t_mlx mlx,
		double angle_step)
{
	int		i;
	int		h_v;
	double	distance;

	i = 0;
	h_v = 0;
	distance = 0;
	while (i < nbr_rays)
	{
		distance = ft_draw_ray(start_angle, *(mlx).player, mlx, &h_v);
		if (h_v == 1)
			ft_draw_wall(i, distance, mlx, ft_strdup("255, 0, 0"));
		else if (h_v == 2)
			ft_draw_wall(i, distance, mlx, ft_strdup("63, 75, 69"));
		start_angle = ft_limit_angle(fmod((start_angle + angle_step), 360));
		distance = distance;
		i++;
	}
}

void	ft_draw_all_rays(t_player *player, t_mlx *mlx)
{
	double	angle_step;
	double	start_angle;
	int		nbr_rays;

	nbr_rays = player->nb_rays;
	angle_step = player->fov / nbr_rays;
	start_angle = ft_limit_angle(fmod(player->angle - (player->fov / 2), 360));
	ft_loop_wall(start_angle, nbr_rays, *mlx, angle_step);
}
