/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_render.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irakotom <irakotom@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/13 13:18:20 by irakotom          #+#    #+#             */
/*   Updated: 2025/08/13 16:48:39 by irakotom         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../../../includes/header.h"

int	ft_valid_key(t_player *player)
{
	int	res;

	res = player->w + player->s + player->a + player->d;
	res = res + player->right + player->left;
	if (res == 0)
		return (0);
	else
		return (1);
}
int	ft_valid_mov(t_player *player)
{
	int	res;

	res = player->w + player->s + player->a + player->d;
	if (res == 0)
		return (0);
	else
		return (1);
}


int	ft_render(t_mlx *mlx)
{
	if (ft_valid_key(mlx->player))
	{
		ft_move_angle(mlx->player);
		if(ft_valid_mov(mlx->player))
			ft_move_of_player(mlx->player, *mlx);
		mlx_clear_window(mlx->mlx, mlx->win);
		ft_bzero(mlx->adr, sizeof(void *));
		ft_color_display(mlx);
	}
	return (0);
}
