/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw_all_rays.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fxu-lin <fxu-lin@student.42antananarivo.m  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/14 09:50:33 by fxu-lin           #+#    #+#             */
/*   Updated: 2025/07/14 09:50:33 by fxu-lin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/header.h"

double ft_draw_ray(double angle, t_player player, t_mlx mlx)
{
	t_point	end;

	end = ft_get_end(angle, mlx, player.y, player.x);

	/*t_point a;*/
	/*a.x = player.x; */
	/*a.y = player.y; */
	/*ft_draw_line(a, end, ft_strdup("255,0,255"), &mlx);*/
	return (ft_get_distance(end, player));
}

void ft_loop_wall(double start_angle, double nbr_rays,t_mlx mlx, double angle_step)
{
	int i;
	double distance;

	i = 0;
	distance = 0;
	while (i < nbr_rays)
	{
		distance = ft_draw_ray(start_angle, *(mlx).player, mlx);
		ft_draw_wall(i, distance,mlx, ft_strdup("255, 0, 0"));
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
