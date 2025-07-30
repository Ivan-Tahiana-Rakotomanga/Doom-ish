/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw_all_rays.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fxu-lin <fxu-lin@student.42antananarivo.m  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/14 09:50:33 by fxu-lin           #+#    #+#             */
/*   Updated: 2025/07/16 11:35:45 by irakotom         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/header.h"

double	ft_draw_ray(double angle, t_player player, t_mlx mlx,
		double *dst_text_orient)
{
	t_point	end;
	t_point	pixel;
	double	res;
	int		h_v;

	res = 0.0;
	h_v = 0;
	pixel.x = player.x;
	pixel.y = player.y;
	end = ft_get_end(angle, mlx, pixel, &h_v);
	dst_text_orient[0] = ft_orientation(h_v, angle);
	dst_text_orient[1] = ft_get_x_text(end, mlx.side, dst_text_orient[0]);
	res = ft_get_distance(end, player);
	/**/
	/*t_point a;*/
	/*a.x = player.x;*/
	/*a.y = player.y;*/
	/**/

	/*ft_draw_line(a, end, ft_strdup("0, 0, 255"), &mlx);*/

	res = res * cos(ft_degree_to_radian(fmod(angle - player.angle, 360)));



	return (res);
}

void	ft_loop_wall(double start_angle, double nbr_rays, t_mlx mlx,
		double angle_step)
{
	int		i;
	double	distance;
	double	dst_text_orient[2];

	i = 0;
	dst_text_orient[0] = 0.0;
	dst_text_orient[1] = 0.0;
	distance = 0;
	while (i < nbr_rays)
	{
		distance = ft_draw_ray(start_angle, *(mlx).player, mlx,
				dst_text_orient);
		ft_draw_wall(i, distance, mlx, dst_text_orient);
		(void)distance;
		start_angle = ft_limit_angle(fmod((start_angle + angle_step), 360));
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
