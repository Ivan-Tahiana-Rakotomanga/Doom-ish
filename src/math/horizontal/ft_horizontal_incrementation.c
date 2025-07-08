/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_horizontal_incrementation.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fxu-lin <fxu-lin@student.42antananarivo.m  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/04 18:32:07 by fxu-lin           #+#    #+#             */
/*   Updated: 2025/07/04 18:32:07 by fxu-lin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/header.h"

int ft_horizontal_incrementation_y(t_mlx *mlx, double ray_angle)
{
  int yn;

  yn = 0;
  if (ft_ray_direction(ray_angle) == 1)
    ym = mlx->side;

}
void ft_horizontal_incrementation(t_mlx *mlx, double ray_angle, double player_pos_x, double player_pos_y)
{
  double horizontal_next_pos_x;
  double horizontal_next_pos_y;
  double horizontal_hit_wall_x;
  double horizontal_hit_wall_y;

  horizontal_next_pos_y = ft_horizontal_inter_y(mlx, ray_angle, player_pos_y);
  horizontal_next_pos_x = ft_horizontal_inter_x(mlx, ray_angle, player_pos_x, player_pos_y);
  horizontal_hit_wall_x = 0.0;
  horizontal_hit_wall_y = 0.0;
  while (horizontal_next_pos_x <= mlx->width && horizontal_next_pos_x >= 0 && horizontal_next_pos_y <= mlx->height && horizontal_next_pos_y >= 0)
  {
    if (ft_check_wall(mlx, horizontal_next_pos_x, horizontal_next_pos_y) == 1)
    horizontal_hit_wall_x += 
  }
}
