/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_color_display.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fxu-lin <fxu-lin@student.42antananarivo.m  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 16:06:00 by fxu-lin           #+#    #+#             */
/*   Updated: 2025/06/18 16:44:36 by fxu-lin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/header.h"


void ft_get_temp_size(int *temp_size_x, int *temp_size_y, char **map, t_mlx *mlx)
{ 
  int map_h; 
  int map_w;

  map_h = ft_map_height(map);
  map_w = ft_map_width(map);
  *temp_size_x = mlx->width / map_w;
  *temp_size_y = mlx->height / map_h;

  printf("Ito ilay width %d\n", *temp_size_x*map_w);
}

void ft_draw_img(int i, int j, t_mlx *mlx, int temp_size_x, int temp_size_y, int x, int y)
{  
  int pixel_x;
  int pixel_y;
  int index;

  index = 0;
  pixel_x = (j) * temp_size_x + x;
  pixel_y = (i) * temp_size_y + y;
  index = (pixel_y * mlx->s_line) + (pixel_x * (mlx->bpp) / 8);
  if (pixel_x < mlx->width && pixel_y < mlx->height)
      *(int *)(mlx->adr + index) = mlx->color;
}

void ft_put_pixel(t_mlx *mlx, int i, int j, char **map)
{
  int x;
  int y;
  int temp_size_x;
  int temp_size_y;

  ft_get_temp_size(&temp_size_x, &temp_size_y, map, mlx);
  x = 0;
  y = 0;

  while (y < temp_size_y)
  {
    x = 0;
    while (x < temp_size_x)
    {
      ft_draw_img(i, j, mlx, temp_size_x, temp_size_y, x, y);
      x++;
    }
    y++;
  }
}

void ft_color_display(char **map, t_mlx *mlx)
{
  int i;
  int j;
   
  i = 0;
  while(map[i])
  {
    j = 0;
    while(map[i][j])
    {
      if (map[i][j] == '1')
        mlx->color = (255 << 16) | (0 << 8) | (0);
      else
        mlx->color = (0 << 16) | (255 << 8) | (0);

      ft_put_pixel(mlx, i, j,map);
      j++;
    }
    i++;
  }
  mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->img, 0, 0);
}
