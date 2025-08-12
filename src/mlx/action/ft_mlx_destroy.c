/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mlx_destroy.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fxu-lin <fxu-lin@student.42antananarivo.m  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 14:26:41 by fxu-lin           #+#    #+#             */
/*   Updated: 2025/06/17 14:26:41 by fxu-lin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/header.h"

void	ft_free_utils(t_utils *utils)
{
	free(utils->ea);
	free(utils->no);
	free(utils->so);
	free(utils->we);
}

void	ft_free_all_mlx(t_mlx *mlx)
{
	free(mlx->player);
	ft_free_str(mlx->map);
	free(mlx->mlx);
	free(mlx);
}

void	ft_destroy_img(t_mlx *mlx)
{
	mlx_destroy_image(mlx->mlx, mlx->img);
	mlx_destroy_image(mlx->mlx, mlx->no.img);
	mlx_destroy_image(mlx->mlx, mlx->so.img);
	mlx_destroy_image(mlx->mlx, mlx->wo.img);
	mlx_destroy_image(mlx->mlx, mlx->ea.img);
	free(mlx->utils.no);
	free(mlx->utils.ea);
	free(mlx->utils.so);
	free(mlx->utils.we);
}

void	ft_mlx_destroy(t_mlx *mlx)
{
	mlx_destroy_window(mlx->mlx, mlx->win);
	ft_destroy_img(mlx);
	mlx_loop_end(mlx->mlx);
	mlx_destroy_display(mlx->mlx);
	ft_free_all_mlx(mlx);
	exit(0);
}
