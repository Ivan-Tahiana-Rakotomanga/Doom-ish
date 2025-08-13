/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move_angle.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irakotom <irakotom@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/13 16:48:55 by irakotom          #+#    #+#             */
/*   Updated: 2025/08/13 16:49:28 by irakotom         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/header.h"

double	ft_limit_angle(double angle)
{
	if (angle < 0.0)
	{
		angle = 360 + angle;
	}
	return (angle);
}

void	ft_move_angle(t_player *player)
{
	double	angle_speed;

	angle_speed = player->angle_speed;
	if (player->left)
	{
		player->angle = ft_limit_angle(fmod(player->angle - angle_speed, 360));
	}
	if (player->right)
	{
		player->angle = ft_limit_angle(fmod(player->angle + angle_speed, 360));
	}
}
