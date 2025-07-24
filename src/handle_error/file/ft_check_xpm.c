/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_xpm.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irakotom <irakotom@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/24 17:07:52 by irakotom          #+#    #+#             */
/*   Updated: 2025/07/24 17:53:55 by irakotom         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/header.h"

void	ft_error_xpm(char *one, char *file)
{
	ft_putstr_fd(one, 2);
	ft_putstr_fd(file, 2);
	ft_putstr_fd(" \n", 2);
}

int	ft_free_and_destroy(void *mlx)
{
	mlx_destroy_display(mlx);
	free(mlx);
	return (0);
}

int	ft_check_xpm(char *filename)
{
	void	*mlx;
	t_img	img;

	mlx = mlx_init();
	if (!mlx)
		return (0);
	img.img = mlx_xpm_file_to_image(mlx, filename, &img.width, &img.height);
	if (!img.img)
	{
		ft_error_xpm("Error\nInvalid argument in: ", filename);
		return (ft_free_and_destroy(mlx));
	}
	img.adr = mlx_get_data_addr(img.img, &img.bpp, &img.s_line, &img.endian);
	if (!img.adr)
	{
		ft_error_xpm("Error\nResource temporarily unavailable in :", filename);
		mlx_destroy_image(mlx, img.img);
		return (ft_free_and_destroy(mlx));
	}
	mlx_destroy_image(mlx, img.img);
	mlx_destroy_display(mlx);
	free(mlx);
	return (1);
}
