/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw_ceiling_floor.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irakotom <irakotom@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/12 09:01:59 by irakotom          #+#    #+#             */
/*   Updated: 2025/08/12 09:02:59 by irakotom         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../../../includes/header.h"

void    ft_draw_ceiling_floor(t_mlx mlx)
{
	double	x;
	double	y;
	char	*tmp_color;
	double	tmp_x;
	int color[2];

	x = 0;
	y = 0;
	tmp_x = x;
	tmp_color = NULL;
    color[0] = ft_convert_color(mlx.utils.c);
    color[1] = ft_convert_color(mlx.utils.f);

	while (y < mlx.height)
	{
		x = tmp_x;
		while (x < mlx.width)
		{
			tmp_color = ft_get_address(x, y, &mlx);
			if(y < (double)mlx.height / 2)
				*(unsigned int *)tmp_color = color[0];
			else
				*(unsigned int *)tmp_color = color[1];
			x++;
		}
		y++;
	}
}

