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




void ft_draw_square(t_point a, int size, char *color, t_mlx *mlx)
{
	int x;
	int y;
	int tmp_x;
	char *tmp_color;
	int size_xy[2];

	x = a.x * mlx->side;
	y = a.y * mlx->side;
	tmp_color = NULL;

	size_xy[0] = x + size;
	size_xy[1] = y + size;
	tmp_x = x;

	while(y < size_xy[1])
	{
		x = tmp_x;
		while(x < size_xy[0])
		{
			tmp_color = ft_get_address(x, y, mlx);
			*(unsigned int *) tmp_color = ft_convert_color(color);
			x++;
		}
		y++;
	}
	

}
