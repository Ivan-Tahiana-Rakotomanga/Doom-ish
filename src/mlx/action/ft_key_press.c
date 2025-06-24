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

int	ft_is_wall_y(t_mlx *mlx, int x)
{
	if (mlx->map[x][mlx->y_player] == '1')
		return (1);
	return (0);
}

int	ft_is_wall_x(t_mlx *mlx, int y)
{
	if (mlx->map[mlx->x_player][y] == '1')
		return (1);
	return (0);
}

int	ft_key_press(int code, t_mlx *mlx)
{
	if (code == 65307)
		ft_mlx_destroy(mlx);
	else if (code == 100 && !ft_is_wall_x(mlx, mlx->y_player + 1))
		mlx->y_player = mlx->y_player + 1;
	else if (code == 97 && !ft_is_wall_x(mlx, mlx->y_player - 1))
		mlx->y_player = mlx->y_player - 1;
	else if (code == 119 && !ft_is_wall_y(mlx, mlx->x_player - 1))
		mlx->x_player = mlx->x_player - 1;
	else if (code == 115 && !ft_is_wall_y(mlx, mlx->x_player + 1))
		mlx->x_player = mlx->x_player + 1;
	ft_render(mlx);
	return (0);
}
