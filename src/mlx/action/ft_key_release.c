/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_key_release.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irakotom <irakotom@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/13 16:47:20 by irakotom          #+#    #+#             */
/*   Updated: 2025/08/13 16:48:25 by irakotom         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/header.h"

int	ft_key_release(int code, void *param)
{
	t_player	*player;

	player = ((t_mlx *)param)->player;
	if (code == 119)
		player->w = 0;
	if (code == 115)
		player->s = 0;
	if (code == 97)
		player->a = 0;
	if (code == 100)
		player->d = 0;
	if (code == 65361)
		player->left = 0;
	if (code == 65363)
		player->right = 0;
	return (0);
}
