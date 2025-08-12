/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_key_press.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fxu-lin <fxu-lin@student.42antananarivo.m  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 14:57:31 by fxu-lin           #+#    #+#             */
/*   Updated: 2025/08/12 18:24:56 by irakotom         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/header.h"

void	ft_render(t_mlx *mlx)
{
	ft_bzero(mlx->adr, sizeof(void *));
	ft_color_display(mlx);
}

double	ft_limit_angle(double angle)
{
	if (angle < 0.0)
	{
		angle = 360 + angle;
	}
	return (angle);
}

void ft_move_angle(int code, t_player *player)
{
	double	angle_speed;

	angle_speed = player->angle_speed;
	if (code == 65361)
		player->angle = ft_limit_angle(fmod(player->angle - angle_speed, 360));
	if (code == 65363)
		player->angle = ft_limit_angle(fmod(player->angle + angle_speed, 360));
}

int	ft_key_press(int code, t_mlx *mlx)
{
	t_player	*player;

	player = mlx->player;
	if (code == 65307)
		ft_mlx_destroy(mlx);
	ft_move_angle(code, player);
	ft_move_of_player(code, player, *mlx);
	ft_render(mlx);
	return (0);
}
