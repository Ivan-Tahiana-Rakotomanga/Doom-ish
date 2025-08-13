/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_key_press.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fxu-lin <fxu-lin@student.42antananarivo.m  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 14:57:31 by fxu-lin           #+#    #+#             */
/*   Updated: 2025/08/13 13:20:15 by irakotom         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/header.h"


void ft_key_moov(int code, t_player *player)
{
	if (code  == 119)
		player->w = 1;
	if (code == 115)
		player->s = 1;
	if (code == 97)
		player->a = 1;
	if (code == 100)
		player->d = 1;
}

void ft_key_angle(int code, t_player *player)
{
	if (code == 65361)
		player->left = 1;
	if (code == 65363)
		player->right = 1;
}

int ft_key_press(int code, t_player *player)
{

	ft_key_moov(code, player);
	ft_key_angle(code, player);
	return (0);
}
