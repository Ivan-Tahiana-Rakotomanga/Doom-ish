/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dda.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fxu-lin <fxu-lin@student.42antananarivo.m  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/04 10:28:58 by fxu-lin           #+#    #+#             */
/*   Updated: 2025/07/04 10:28:58 by fxu-lin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/header.h"

double	ft_delta(double a, double b)
{
	return (b - a);
}

t_point	ft_increment_dda(t_point a, t_point b)
{
	t_point	increment;
	double	step;
	double	delta_x;
	double	delta_y;

	increment.x = 0.0;
	increment.y = 0.0;
	delta_x = ft_delta(a.x, b.x);
	delta_y = ft_delta(a.y, b.y);
	step = fmax(fabs(delta_x),fabs(delta_y));;

	increment.x = delta_x / step;
	increment.y = delta_y / step;
	return (increment);
}
