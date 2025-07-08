/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_wall.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fxu-lin <fxu-lin@student.42antananarivo.m  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/04 16:59:51 by fxu-lin           #+#    #+#             */
/*   Updated: 2025/07/04 16:59:51 by fxu-lin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/header.h"

int ft_check_wall(t_mlx *mlx, double horizontal_pos_x, double horizontal_pos_y)
{
  int temp_x;
  int temp_y;
  char **map;

  map = mlx->map;
  temp_x = floor(horizontal_pos_x / mlx->side);
  temp_y = floor(horizontal_pos_y / mlx->side);
  if (map[temp_x][temp_y] == '1')
    return (1);
  return (0);
}
