/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_degree_to_radian.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fxu-lin <fxu-lin@student.42antananarivo.m  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/14 09:48:56 by fxu-lin           #+#    #+#             */
/*   Updated: 2025/07/14 09:48:56 by fxu-lin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/header.h"

double	ft_degree_to_radian(double degree)
{
	double	radian;
	double	pi;

	pi = 3.14159265358979323846;
	radian = degree * (pi / 180.0);
	if (radian < 0)
		radian += 2 * pi;
	return (radian);
}
