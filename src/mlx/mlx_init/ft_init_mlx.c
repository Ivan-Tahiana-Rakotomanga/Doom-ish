/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_mlx.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fxu-lin <fxu-lin@student.42antananarivo.m  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 10:02:55 by fxu-lin           #+#    #+#             */
/*   Updated: 2025/06/18 16:08:55 by fxu-lin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/header.h"

t_mlx *ft_init_mlx(t_mlx *mlx)
{
  mlx = malloc(sizeof(t_mlx));
  if (!mlx)
    return (ft_free_mlx(mlx));

  ft_init_size_window(mlx, 800, 600);
  ft_init_key(mlx);
  if (!ft_check_mlx(mlx, "cub3D"))
    return(ft_free_mlx(mlx));

  return (mlx);
}

int main(int argc, char **argv)
{
  (void)argc;
  (void)argv;
  t_mlx *mlx;

  char *map[9] = {"0000000000",
                 "1111111111",
                 "0011110011",
                 "1100110000",
                 "0000000000",
                 "1111111111",
                 "0011110011",
                 "1100110000",
                 NULL
                };
  mlx = NULL;
  mlx = ft_init_mlx(mlx);
  if (!mlx)
    return (0);
  ft_hook(mlx);
  ft_color_display(map,mlx);
  mlx_loop(mlx->mlx);
  return (0);
}
