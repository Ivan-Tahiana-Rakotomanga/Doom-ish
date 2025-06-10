/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_valid_color.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fxu-lin <fxu-lin@student.42antananarivo.m  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/10 10:17:50 by fxu-lin           #+#    #+#             */
/*   Updated: 2025/06/10 10:17:50 by fxu-lin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/header.h"

int	ft_valid_color(int color)
{
	if (color < 0 || color > 255)
	{
		ft_putstr_fd("Error\nColor must be between 0 and 255\n", 2);
		return (0);
	}
	return (1);
}
