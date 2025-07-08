/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw_square.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irakotom <irakotom@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 17:18:07 by irakotom          #+#    #+#             */
/*   Updated: 2025/07/02 18:47:29 by irakotom         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/header.h"

void ft_draw_square(t_point pixel, int size, char *color, t_mlx *mlx)
{
	double x;
	double  y;
	char *tmp_color;
	double tmp_x;
	double xy_limits[2];

	x = pixel.x;
	y = pixel.y;
	tmp_x = x;
	tmp_color = NULL;
	xy_limits[0] = x + size;
	xy_limits[1] = y + size;
	
	while(y < xy_limits[1])
	{
		x = tmp_x;
		while(x < xy_limits[0]) 
		{
			tmp_color = ft_get_address(x, y, mlx);
			*(unsigned int *) tmp_color = ft_convert_color(color);
			x++;
		}
		y++;
	}

}
