/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irakotom <irakotom@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/04 13:05:56 by irakotom          #+#    #+#             */
/*   Updated: 2025/06/11 13:26:00 by irakotom         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/header.h"

/*void	ft_print_strs(char **strs)
{
	int		i;

	i = 0;
	printf("\nIto ny print an'ilay strs\n");
	while (strs[i])
	{
		printf("%s\n", strs[i]);
		i++;
	}
	printf("\n");
}*/

/*int	main(int argc, char **argv)
{

	if (argc == 2)
	{
	char ** map;
		t_mlx	*mlx;
	mlx = NULL;
	map = NULL;
		if (!ft_check_file(argv[1], &map))
			return (0);

  mlx = ft_init_mlx(mlx, map);
	if (!mlx)
		return (0);
	ft_color_display(mlx);
	ft_hook(mlx);
  mlx_loop(mlx->mlx);
	ft_free_str(map);
	}
	return (0);
}*/
/*int	main(int argc, char **argv)
{
	t_mlx	*mlx;
	char	*map[9] = {"0000000000", "1111111111", "0011110011", "1100110000",
			"0000000000", "1111111111", "0011110011", "1100110000", NULL};

	(void)argc;
	(void)argv;
	mlx = NULL;
	mlx = ft_init_mlx(mlx, map);
	if (!mlx)
		return (0);
	ft_hook(mlx);
	ft_color_display(mlx);
	mlx_loop(mlx->mlx);
	return (0);
}*/
