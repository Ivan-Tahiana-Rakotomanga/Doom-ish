/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_on_screen.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irakotom <irakotom@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 10:08:44 by irakotom          #+#    #+#             */
/*   Updated: 2025/07/16 10:08:44 by irakotom         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/header.h"

int	ft_on_screen(double x, double y, t_mlx mlx)
{
	if (x < 0 || mlx.width <= x)
		return (0);
	if (y < 0 || mlx.height <= y)
		return (0);
	return (1);
}
