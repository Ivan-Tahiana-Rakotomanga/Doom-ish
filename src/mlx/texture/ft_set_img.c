/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_set_img.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irakotom <irakotom@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/23 12:46:57 by irakotom          #+#    #+#             */
/*   Updated: 2025/07/23 12:55:18 by irakotom         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/header.h"

void ft_set_img(t_img *img, char *filename, void *mlx_ptr)
{
	img->img = mlx_xpm_file_to_image(mlx_ptr, filename, &img->width, &img->height);
	img->adr = mlx_get_data_addr(&img->img, &img->bpp, &img->s_line, &img->endian);
}
