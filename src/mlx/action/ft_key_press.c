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

void ft_moov_of_player(int code, t_player *player)
{	
	double speed;

	speed = player->speed;
    if (code == 119)
	 player->y = player->y - speed;
	else if (code == 115)
	 player->y = player->y + speed;
	else if (code == 100)
	 player->x = player->x + speed;
	else if (code == 97)
	 player->x = player->x - speed;
}

void ft_moov_angle(int code, t_player *player)
{
	double angle_speed;  

	angle_speed = player->angle_speed;

	if (code == 65361)
		player->angle = player->angle + angle_speed;
	else if (code == 65363)
		player->angle = player->angle - angle_speed;
}

int	ft_key_press(int code, t_mlx *mlx)
{
	t_player * player;

	player = mlx->player;
	if (code == 65307)
		ft_mlx_destroy(mlx);
	ft_moov_of_player(code, player);
	ft_moov_angle(code, player);

	
	ft_render(mlx);
	return (0);
}
