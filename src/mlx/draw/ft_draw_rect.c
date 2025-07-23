/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw_rect.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irakotom <irakotom@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 10:10:09 by irakotom          #+#    #+#             */
/*   Updated: 2025/07/16 10:10:11 by irakotom         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/header.h"

char	*ft_get_address_textures(int x, int y,int y_max, t_img *img, t_mlx *mlx)
{
	char	*address;

	y = ft_rules_of_three(y, y_max, mlx->height);

	address = img->adr + (y * img->s_line + x * (img->bpp / 8));
	return (address);
}

void ft_draw_rect_textures(t_point a, t_point b, t_img *img, t_mlx *mlx)
{
	double	x;
	double	y;
	char	*tmp_color;
	double	tmp_x;

	x = a.x;
	y = a.y;
	tmp_x = x;
	tmp_color = NULL;
	while (y < b.y)
	{
		x = tmp_x;
		while (x < b.x)
		{
			tmp_color = ft_get_address(x, y, mlx);
			*(unsigned int *)tmp_color = *(unsigned int *) ft_get_address_textures(x, y,b.y, img,mlx);
			x++;
		}
		y++;
	}
}

void	ft_draw_rect(t_point a, t_point b, char *color, t_mlx *mlx)
{
	double	x;
	double	y;
	char	*tmp_color;
	double	tmp_x;

	x = a.x;
	y = a.y;
	tmp_x = x;
	tmp_color = NULL;
	while (y < b.y)
	{
		x = tmp_x;
		while (x < b.x)
		{
			tmp_color = ft_get_address(x, y, mlx);
			*(unsigned int *)tmp_color = ft_convert_color(color);
			x++;
		}
		y++;
	}
}
