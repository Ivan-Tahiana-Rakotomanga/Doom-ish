/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flood_fill.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fxu-lin <fxu-lin@student.42antananarivo.m  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 08:28:38 by fxu-lin           #+#    #+#             */
/*   Updated: 2025/06/17 12:57:41 by irakotom         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/header.h"

/*
void	ft_print_map(char **map)
{
	int	i;

	i = 0;
	while (map[i])
	{
		printf("%s\n", map[i]);
		i++;
	}
}

char	**ft_copy_map(char **map, int height)
{
	char	**copy;
	int		i;

	i = 0;
	copy = malloc(sizeof(char *) * (height + 1));
	if (!copy)
		return (NULL);
	while (i < height)
	{
		copy[i] = ft_strdup(map[i]);
		i++;
	}
	copy[height] = NULL;
	return (copy);
}

void	ft_find_start(int *start_x, int *start_y, int height, int width,
		char **map)
{
	int	j;
	int	i;

	j = 0;
	i = 0;
	while (i < height && *start_x == -1)
	{
		j = 0;
		while (j < width)
		{
			if (ft_is_orientation(map[i][j]))
			{
				*start_x = i;
				*start_y = j;
				return ;
			}
			j++;
		}
		i++;
	}
}

int	ft_flood_fill(int x, int y, char **map, int width, int height)
{
	if (x < 0 || y < 0 || x >= height || y >= width)
		return (0);
	if (map[x][y] == ' ' || map[x][y] == '\0')
		return (0);
	if (map[x][y] == '1' || map[x][y] == 'x')
		return (1);
	map[x][y] = 'x';
	return (ft_flood_fill(x + 1, y, map, width, height) && ft_flood_fill(x - 1,
			y, map, width, height) && ft_flood_fill(x, y + 1, map, width,
			height) && ft_flood_fill(x, y - 1, map, width, height));
}

	int		height;
	char	*original_map[] = {"111111", "100000", "1111N1", "111111", NULL};
	int		width;
	char	**map;
	int		x_start;
	int		y_start;
	int		result;

	height = 4;
	printf("Début de la map --\n");
	ft_print_map(original_map);
	width = ft_strlen(original_map[0]);
	map = ft_copy_map(original_map, height);
	x_start = -1;
	y_start = -1;
	ft_find_start(&x_start, &y_start, height, width, map);
	printf("Ito ny x=%d ny y=%d\n", x_start, y_start);
	if (x_start == -1)
	{
		printf("Tsisy orientation\n");
		return (0);
	}
	map[x_start][y_start] = '0';
	result = ft_flood_fill(x_start, y_start, map, width, height);
	if (result)
		printf("Midy tsara\n");
	else
		printf("Erreur\n");
	ft_free_str(map);
	return (0);
}*/




/*int main(int argc, char **argv)
{
	if(argc == 2)
	{
		int	fd;
		t_map *map;

		map = NULL;
		fd = open(argv[1], O_RDONLY);


		if(!ft_fill_map(&map,fd))
			return (0);


		ft_print_map(map);
		ft_free_map(&map);
		close(fd);

	}
	return (0);
}*/
