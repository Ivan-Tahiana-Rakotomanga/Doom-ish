/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move_player.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irakotom <irakotom@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/12 17:17:50 by irakotom          #+#    #+#             */
/*   Updated: 2025/08/13 16:58:34 by irakotom         ###   ########.fr       */
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

t_point	ft_set_coordinate(t_player *player, t_point *b, double angle, int index)
{
	double	speed;
	t_point	a;

	speed = player->speed;
	a.x = player->x;
	a.y = player->y;
	a = ft_coordinate(angle, a, speed, index);
	*b = ft_coordinate(angle, a, speed + 10, index);
	return (a);
}

t_point	ft_get_coordinate(t_player *player, t_point *b)
{
	double	angle;
	int		index;

	angle = player->angle;
	index = 2;
	if (player->w && player->d)
		angle = angle + 225;
	else if (player->a && player->w)
		angle = angle - 225;
	else if (player->a && player->s)
		angle = angle + 45;
	else if (player->s && player->d)
		angle = angle - 45;
	else
	{
		if (player->w)
			index = 1;
		if (player->d)
			angle = angle - 90;
		if (player->a)
			angle = angle + 90;
	}
	return (ft_set_coordinate(player, b, angle, index));
}

void	ft_move_of_player(t_player *player, t_mlx mlx)
{
	t_point	a;
	t_point	b;

	b.x = 0;
	b.y = 0;
	a = ft_get_coordinate(player, &b);
	if (!ft_is_wall(b.x, b.y, mlx))
	{
		player->x = a.x;
		player->y = a.y;
	}
}
