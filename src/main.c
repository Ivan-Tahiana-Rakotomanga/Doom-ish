/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irakotom <irakotom@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/04 13:05:56 by irakotom          #+#    #+#             */
/*   Updated: 2025/07/23 12:37:37 by irakotom         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/header.h"

int	main(int argc, char **argv)
{
	t_mlx	*mlx;
	char	**map;
	t_utils	utils;

	mlx = NULL;
	map = NULL;
	if (argc == 2)
	{
		if (!ft_check_file(argv[1], &map, &utils))
			return (0);
		mlx = ft_init_mlx(mlx, map, utils);
		if (!mlx)
			return (0);
		ft_color_display(mlx);
		ft_hook(mlx);
		mlx_loop(mlx->mlx);
		ft_free_str(map);
		ft_free_mlx(mlx);
	}
	else
		ft_putstr_fd("Error\nThere is more or less than one argument\n", 2);
	return (0);
}
