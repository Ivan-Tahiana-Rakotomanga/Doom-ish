/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_key_press.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fxu-lin <fxu-lin@student.42antananarivo.m  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 14:57:31 by fxu-lin           #+#    #+#             */
/*   Updated: 2025/06/17 15:01:20 by fxu-lin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/header.h"

int ft_key_press(int code, t_mlx *mlx)
{
  if (code == 65307) 
    ft_mlx_destroy(mlx);
  else if(code == 100)
    mlx->change_x = mlx->change_x - 0.5;
  else if(code == 97)
    mlx->change_x = mlx->change_x + 0.5;
  else if(code == 119)
    mlx->change_y = mlx->change_y + 0.5;
  else if(code == 115)
    mlx->change_y = mlx->change_y - 0.5;
  return (0);
}
