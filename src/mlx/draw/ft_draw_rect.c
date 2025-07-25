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



double ft_get_percent(double value, double max)
{
	return (floor(value * 100 / max));
}

int ft_get_y_percent(double percent, double height_img)
{
	return ((int)floor((percent * height_img) / 100));
}

int ft_get_new_y(double value, double height_wall, double height_img)
{
	double percent;
	int res;

	percent = ft_get_percent(value, height_wall);
	/*printf("Ito ilay pourcentage %f nefa ny value %f de ny height_wall \n",percent, height_wall);*/
	res = ft_get_y_percent(percent, height_img);
	/*printf("Ito ilay y %d nefa ny max_img=%f ito\n", res,height_img);*/
	return (res);
}
/*int main()*/
/*{*/
/*	printf("Ito ny res %d\n", ft_get_new_y(12,64,128));*/
/**/
/*}*/


char	*ft_get_address_textures(int y, int y_max, int h, t_img img, double dst_text, t_mlx *mlx)
{
	char	*address;
	int x;



	x = ft_rules_of_three(dst_text, mlx->side, img.width);
	(void)h;
	y = ft_get_new_y(y,y_max,img.height); 

	
	address = img.adr + (y * img.s_line + x * (img.bpp / 8));
	return (address);
}

t_img	ft_get_texture(t_mlx mlx, int index)
{
	if (index == 1)
		return (mlx.no);
	else if (index == 2)
		return (mlx.so);
	else if (index == 3)
		return (mlx.ea);
	else
		return (mlx.wo);
}

void	ft_draw_rect_textures(t_point a, t_point b, t_mlx *mlx, double dst_text, int orient, double height_wall)
{
	double	x;
	double	y;
	char	*tmp_color;
	double	tmp_x;
	double	h;

	h = height_wall;
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
			*(unsigned int *)tmp_color = *(unsigned int *)ft_get_address_textures(
					y, b.y, h, ft_get_texture(*mlx, orient), dst_text, mlx);
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
