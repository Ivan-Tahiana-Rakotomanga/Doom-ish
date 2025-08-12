/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move_player.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irakotom <irakotom@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/12 17:17:50 by irakotom          #+#    #+#             */
/*   Updated: 2025/08/12 17:27:06 by irakotom         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/header.h"

t_point	ft_coordinate(double angle, t_point b, double speed, int add_substract)
{
	if (add_substract == 1)
	{
		b.x = b.x + cos(ft_degree_to_radian(fmod(angle, 360))) * speed;
		b.y = b.y + sin(ft_degree_to_radian(fmod(angle, 360))) * speed;
	}
	else if (add_substract == 2)
	{
		b.x = b.x - cos(ft_degree_to_radian(fmod(angle, 360))) * speed;
		b.y = b.y - sin(ft_degree_to_radian(fmod(angle, 360))) * speed;
	}
	return (b);
}

t_point	ft_get_coordinate(int code, t_player player, t_point *b, double step)
{
	double	speed;
	double	angle;
	t_point	a;

	speed = player.speed;
	angle = player.angle;
	a.x = player.x;
	a.y = player.y;
	if (code == 119)
	{
		a = ft_coordinate(angle, a, speed, 1);
		*b = ft_coordinate(angle, a, speed + step, 1);
	}
	if (code == 115)
	{
		a = ft_coordinate(angle, a, speed, 2);
		*b = ft_coordinate(angle, a, speed + step, 2);
	}
	if (code == 100)
	{
		a = ft_coordinate(angle - 90, a, speed, 2);
		*b = ft_coordinate(angle - 90, a, speed + step, 2);
	}
	if (code == 97)
	{
		a = ft_coordinate(angle + 90, a, speed, 2);
		*b = ft_coordinate(angle + 90, a, speed + step, 2);
	}
	return (a);
}

int	ft_move_of_player(int code, t_player *player, t_mlx mlx)
{
	t_point	a;
	t_point	b;

	a = ft_get_coordinate(code, *player, &b, 10);
	if (0 < a.x && a.x < mlx.width && 0 < a.y && a.y < mlx.height)
	{
		if (!ft_is_wall(b.x, b.y, mlx))
		{
			player->x = a.x;
			player->y = a.y;
			return (1);
		}
	}
	return (0);
}
