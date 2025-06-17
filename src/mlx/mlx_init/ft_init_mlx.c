/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_mlx.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fxu-lin <fxu-lin@student.42antananarivo.m  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 10:02:55 by fxu-lin           #+#    #+#             */
/*   Updated: 2025/06/17 14:24:51 by fxu-lin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/header.h"

t_mlx *ft_init_mlx(t_mlx *mlx)
{
  mlx = malloc(sizeof(t_mlx));
  mlx->width = 800;
  mlx->height = 600;
  mlx->change_x = 0.0;
  mlx->change_y = 0.0;
  mlx->mlx = mlx_init(); 
  if (!mlx->mlx)
  {
    return (ft_free_mlx(mlx));
  }
  mlx->win = mlx_new_window(mlx->mlx, mlx->width, mlx->height, "cub3D");
  if (!mlx->win)
    return (ft_free_mlx(mlx));
  mlx->img = mlx_new_image(mlx->mlx, mlx->width, mlx->height);
  if (!mlx->img)
    return (ft_free_mlx(mlx));
  mlx->adr = mlx_get_data_addr(mlx->img, &mlx->bpp, &mlx->s_line, &mlx->endian);
  if (!mlx->adr)
    return (ft_free_mlx(mlx));;
  return (mlx);
}

int main(int argc, char **argv)
{
  (void)argc;
  (void)argv;
  t_mlx *mlx;

  char *map[5] = {"0000",
                 "1111",
                 "0011",
                 "1100",
                 NULL
                };
  mlx = NULL;
  mlx = ft_init_mlx(mlx);
  if (!mlx)
    return (0);
  ft_hook(mlx);
  ft_color_display(map, mlx);
  mlx_loop(mlx->mlx);
  return (0);
}
