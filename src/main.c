/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irakotom <irakotom@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/04 13:05:56 by irakotom          #+#    #+#             */
/*   Updated: 2025/07/14 09:53:46 by fxu-lin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/header.h"

/*void	ft_print_strs(char **strs)
{
	int		i;
		char **map;
		t_mlx *mlx;
	t_mlx	*mlx;
	char	**map;
	t_mlx	*mlx;
	char	**map;
	t_mlx	*mlx;
	char	**map;

	i = 0;
	printf("\nIto ny print an'ilay strs\n");
	while (strs[i])
	{
		printf("%s\n", strs[i]);
		i++;
	}
	printf("\n");
}*/
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
/*int	main(int argc, char **argv)*/
/*{*/
/**/
/*	if (argc == 2)*/
/*	{*/
/*	char ** map;*/
/*		t_mlx	*mlx;*/
/*	mlx = NULL;*/
/*	map = NULL;*/
/*		if (!ft_check_file(argv[1], &map))*/
/*			return (0);*/
/**/
/*  mlx = ft_init_mlx(mlx, map);*/
/*	if (!mlx)*/
/*		return (0);*/
/*	ft_color_display(mlx);*/
/*	ft_hook(mlx);*/
/*  mlx_loop(mlx->mlx);*/
/*	ft_free_str(map);*/
/*	}*/
/*	return (0);*/
/*}*/
