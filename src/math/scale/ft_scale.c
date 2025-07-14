/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_scale.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fxu-lin <fxu-lin@student.42antananarivo.m  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/14 09:49:47 by fxu-lin           #+#    #+#             */
/*   Updated: 2025/07/14 09:49:47 by fxu-lin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/header.h"

double	ft_coordinate_to_pixel(double value, double side)
{
	return (value * side);
}

double	ft_pixel_to_coordinate(double value, double side)
{
	if (side == 0)
		return (0);
	return (floor(value / side));
}
