/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_horizontal_intersection.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fxu-lin <fxu-lin@student.42antananarivo.m  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/04 10:18:34 by fxu-lin           #+#    #+#             */
/*   Updated: 2025/07/04 10:18:34 by fxu-lin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/header.h"
#include <math.h>

int ft_horizontal_inter_y(t_mlx *mlx, double ray_angle, double player_pos_y)
{
  double horizontal_pos_y;
  int side;

  horizontal_pos_y = 0.0;
  side = mlx->side;
  if (ft_ray_direction(ray_angle) == 1)
    horizontal_pos_y = floor(player_pos_y / side) * side - 1;
  else if (ft_ray_direction(ray_angle) == -1)
      horizontal_pos_y = floor(player_pos_y / side) * side + side;
  return (horizontal_pos_y);
}

int ft_horizontal_inter_x(t_mlx *mlx, double ray_angle, double player_pos_x, double player_pos_y)
{
  double horizontal_pos_x;
  double horizontal_pos_y;

  horizontal_pos_y = ft_horizontal_inter_y(mlx, ray_angle, player_pos_y);
  horizontal_pos_x = (horizontal_pos_y - player_pos_y) / tan(ray_angle) + player_pos_x;
  return (horizontal_pos_x);
}
