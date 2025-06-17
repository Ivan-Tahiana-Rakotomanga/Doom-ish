/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_color.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fxu-lin <fxu-lin@student.42antananarivo.m  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 16:06:00 by fxu-lin           #+#    #+#             */
/*   Updated: 2025/06/17 16:06:00 by fxu-lin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/header.h"

void ft_color_map(char **map, t_mlx *mlx, int index)
{
  int i;
  int j;

  i = 0;
  while(map[i])
  {
    j = 0;
    while(map[i][j])
    {
      if (map[i][j] == 1)
        *(int *)(mlx->adr + index) = 0;
      else if (map[i][j] == 0)
        *(int *)(mlx->adr + index) = 255;
      j++;
    }
    i++;
  }
}

void ft_color_display(char **map, t_mlx *mlx)
{
  int x;
  int y;
  int index;

  index = 0;
  y = 0;
  x = 0;
  while (y <= mlx->height)
  {
    x = 0;
    while (x <= mlx->width)
    {
      index = (y * mlx->s_line) + (x * (mlx->bpp) / 8);
      ft_color_map(map, mlx, index);
      x++;
    }
    y++;
  }
  mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->img, 0, 0);
}
