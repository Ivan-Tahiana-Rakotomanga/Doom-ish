/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw_rect_textures.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fxu-lin <fxu-lin@student.42antananarivo    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/29 15:38:18 by fxu-lin           #+#    #+#             */
/*   Updated: 2025/08/25 16:26:32 by fxu-lin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/header.h"

t_img	ft_get_texture(t_mlx mlx, int index)
{
	if (index == 1)
		return (mlx.no);
	else if (index == 2)
		return (mlx.ea);
	else if (index == 3)
		return (mlx.wo);
	else
		return (mlx.so);
}

unsigned int	*ft_get_address_textures(int y, int h, t_mlx mlx,
		double *dst_orient)
{
	char	*address;
	int		x;
	t_img	img;

	img = ft_get_texture(mlx, (int)dst_orient[0]);
	if ((int)dst_orient[0] == 2 || (int)dst_orient[0] == 3)
		x = ft_rules_of_three(dst_orient[1], mlx.side, img.width);
	else
		x = (img.width) - ft_rules_of_three(dst_orient[1], mlx.side, img.width);
	if (y > 0)
		y = ft_get_new_y(y, h, img.height);
	else
		y = 0;
	address = img.adr + (y * img.s_line + x * (img.bpp / 8));
	return ((unsigned int *)address);
}

char	*ft_get_tmp_color(t_point a, t_mlx mlx)
{
	if (a.y <= 0)
		return (ft_get_address(a.x, 0, &mlx));
	else if (mlx.height <= a.y)
		return (ft_get_address(a.x, mlx.height, &mlx));
	else
		return (ft_get_address(a.x, a.y, &mlx));
}

void	ft_draw_rect_textures(t_point a, t_point b, t_mlx mlx,
		double *dst_orient)
{
	char	*tmp_color;
	double	h;
	double	tmp_x;
	double	s;

	s = 0.0;
	h = b.y - a.y;
	tmp_x = a.x;
	tmp_color = NULL;
	ft_draw_ceiling_floor(mlx, a, b);
	while (a.y < b.y)
	{
		a.x = tmp_x;
		while (a.x < b.x)
		{
			tmp_color = ft_get_tmp_color(a, mlx);
			*(unsigned int *)tmp_color = *ft_get_address_textures(s, h, mlx,
					dst_orient);
			a.x++;
		}
		s++;
		a.y++;
	}
}
