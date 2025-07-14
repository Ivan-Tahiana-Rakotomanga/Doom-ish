/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_address.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irakotom <irakotom@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 17:01:18 by irakotom          #+#    #+#             */
/*   Updated: 2025/07/02 17:06:24 by irakotom         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/header.h"

char	*ft_get_address(int x, int y, t_mlx *mlx)
{
	char	*address;

	address = mlx->adr + (y * mlx->s_line + x * (mlx->bpp / 8));
	return (address);
}
