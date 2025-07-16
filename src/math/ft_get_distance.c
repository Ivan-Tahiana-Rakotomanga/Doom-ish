/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_distance.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irakotom <irakotom@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 10:08:36 by irakotom          #+#    #+#             */
/*   Updated: 2025/07/16 10:08:36 by irakotom         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/header.h"

double	ft_get_distance(t_point end, t_player player)
{
	double	x;
	double	y;

	x = end.x - player.x;
	x = x * x;
	y = end.y - player.y;
	y = y * y;
	return (sqrt(x) + sqrt(y));
}
