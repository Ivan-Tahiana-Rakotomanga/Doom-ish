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

void	ft_find_start(int *start_x, int *start_y, char **map)
{
	int	j;
	int	i;
	int	width;
	int	height;

	j = 0;
	i = 0;
	width = ft_strlen(map[0]);
	height = ft_strs_len(map);
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

int	ft_check_flood(int x, int y, char **map, int height)
{
	int	res;

	res = 1;
	res = res && ft_flood_fill(x + 1, y, map, height);
	res = res && ft_flood_fill(x - 1, y, map, height);
	res = res && ft_flood_fill(x, y + 1, map, height);
	res = res && ft_flood_fill(x, y - 1, map, height);
	return (res);
}

int	ft_flood_fill(int x, int y, char **map, int height)
{
	int	width;
	int	res;

	width = ft_strlen(map[0]);
	res = 0;
	if (x < 0 || y < 0 || x >= height || y >= width)
		return (0);
	if (map[x][y] == ' ' || map[x][y] == '\0')
		return (0);
	if (map[x][y] == '1' || map[x][y] == 'x')
		return (1);
	map[x][y] = 'x';
	res = ft_check_flood(x, y, map, height);
	return (res);
}

int	ft_map_is_closed(char **map)
{
	int		height;
	int		x_start;
	int		y_start;
	char	**copy_map;
	int		res;

	x_start = -1;
	res = 1;
	y_start = -1;
	height = ft_strs_len(map);
	copy_map = ft_copy_map(map, height);
	ft_find_start(&x_start, &y_start, copy_map);
	if (x_start == -1)
	{
		ft_putstr_fd("Error\nThere is no player in the map\n", 2);
		return (free(copy_map), free(map), 0);
	}
	copy_map[x_start][y_start] = '0';
	if (!ft_flood_fill(x_start, y_start, copy_map, height))
	{
		ft_putstr_fd("Error\nThe map is not closed\n", 2);
		res = 0;
	}
	ft_free_str(copy_map);
	return (res);
}
