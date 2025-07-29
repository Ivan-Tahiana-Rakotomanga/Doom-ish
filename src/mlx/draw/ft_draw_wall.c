/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw_wall.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irakotom <irakotom@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 10:10:00 by irakotom          #+#    #+#             */
/*   Updated: 2025/07/16 11:30:58 by irakotom         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/header.h"

void	ft_draw_wall(int i, double distance, t_mlx mlx, double *dst_text_orient)
{
	double	width_one_wall;
	double	height_wall;
	t_point	start;
	t_point	end;

	width_one_wall = mlx.width_one_wall;
	height_wall = ft_get_height_wall(*(mlx).player, mlx, distance, 32);
	start.x = i * width_one_wall;
	start.y = ((double)mlx.height / 2) - (height_wall / 2);
	end.x = start.x + width_one_wall;
	end.y = start.y + height_wall;
	ft_draw_rect_textures(start, end, mlx, dst_text_orient);
}
