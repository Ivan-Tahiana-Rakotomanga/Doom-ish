/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_duplicate_color.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fxu-lin <fxu-lin@student.42antananarivo.m  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/10 10:30:42 by fxu-lin           #+#    #+#             */
/*   Updated: 2025/06/10 10:30:42 by fxu-lin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/header.h"

int	ft_is_duplicate_color(int floor, int ceiling)
{
	if (floor == ceiling)
	{
		ft_putstr_fd("Error\nFloor and ceiling colors must be different", 2);
	}
	return (1);
}
