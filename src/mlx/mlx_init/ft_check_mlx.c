/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_mlx.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fxu-lin <fxu-lin@student.42antananarivo.m  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 16:06:52 by fxu-lin           #+#    #+#             */
/*   Updated: 2025/06/18 16:06:52 by fxu-lin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/header.h"

int	ft_check_mlx(t_mlx *mlx, char *name)
{
	mlx->mlx = mlx_init();
	if (!mlx->mlx)
		return (0);
	mlx->win = mlx_new_window(mlx->mlx, mlx->width, mlx->height, name);
	if (!mlx->win)
		return (0);
	mlx->img = mlx_new_image(mlx->mlx, mlx->width, mlx->height);
	if (!mlx->img)
		return (0);
	mlx->adr = mlx_get_data_addr(mlx->img, &mlx->bpp, &mlx->s_line,
			&mlx->endian);
	if (!mlx->adr)
		return (0);
	return (1);
}
