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

void	ft_render(t_mlx *mlx)
{
	mlx_clear_window(mlx->mlx, mlx->win);
	ft_color_display(mlx);
}


int	ft_key_press(int code, t_mlx *mlx)
{
    printf("Ito ilay code %d\n", code);
	if (code == 65307)
		ft_mlx_destroy(mlx);
	else if (code == 100)
		mlx->y_player = mlx->y_player + 1;
	else if (code == 97)
		mlx->y_player = mlx->y_player - 1;
	else if (code == 119)
		mlx->x_player = mlx->x_player - 1;
	else if (code == 115)
		mlx->x_player = mlx->x_player + 1;
  ft_render(mlx);
	return (0);
}
