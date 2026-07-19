/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_close_window.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fxu-lin <fxu-lin@student.42antananarivo.m  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 14:28:37 by fxu-lin           #+#    #+#             */
/*   Updated: 2025/06/17 14:28:37 by fxu-lin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/header.h"

int	ft_close_window(void *param)
{
	t_mlx	*mlx;

	mlx = (t_mlx *)param;
	ft_mlx_destroy(mlx);
	return (0);
}
