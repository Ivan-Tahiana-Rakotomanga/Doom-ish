/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irakotom <irakotom@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/04 13:05:56 by irakotom          #+#    #+#             */
/*   Updated: 2025/07/16 10:15:03 by irakotom         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/header.h"

int	main(int argc, char **argv)
{
	t_mlx *mlx;
	char **map;

	mlx = NULL;
	map = NULL;
	if (argc == 2)
	{
		if (!ft_check_file(argv[1], &map))
			return (0);
		mlx = ft_init_mlx(mlx, map);
		if (!mlx)
			return (0);
		ft_color_display(mlx);
		ft_hook(mlx);
		mlx_loop(mlx->mlx);
		ft_free_str(map);
		ft_free_mlx(mlx);
	}
	return (0);
}

