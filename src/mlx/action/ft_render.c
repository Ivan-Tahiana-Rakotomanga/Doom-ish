/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_render.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irakotom <irakotom@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/13 13:18:20 by irakotom          #+#    #+#             */
/*   Updated: 2025/08/13 13:18:45 by irakotom         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../../../includes/header.h"
#include <stdio.h>

double	ft_limit_angle(double angle)
{
	if (angle < 0.0)
	{
		angle = 360 + angle;
	}
	return (angle);
}

void ft_move_angle(t_player *player)
{
	double	angle_speed;

	angle_speed = player->angle_speed;
	if (player->left)
	{

		player->angle = ft_limit_angle(fmod(player->angle - angle_speed, 360));
		player->left = 0;
	}
	if (player->right)
	{
		player->angle = ft_limit_angle(fmod(player->angle + angle_speed, 360));
		player->right = 0;
	}
}

int ft_render(t_mlx *mlx)
{

	ft_move_angle(mlx->player);
	ft_move_of_player(mlx->player, *mlx);

	mlx_clear_window(mlx->mlx, mlx->win);
	ft_bzero(mlx->adr, sizeof(void *));
	ft_color_display(mlx);
	return (0);
}
