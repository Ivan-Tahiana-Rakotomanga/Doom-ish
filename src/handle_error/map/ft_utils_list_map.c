/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils_list_map.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irakotom <irakotom@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 10:14:52 by irakotom          #+#    #+#             */
/*   Updated: 2025/06/17 16:16:38 by irakotom         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/header.h"

int	ft_get_height_map(t_map *map)
{
	int	height;

	height = 0;
	while (map)
	{
		height++;
		map = map->next;
	}
	return (height);
}

int	ft_get_width_map(t_map *map)
{
	int		max;
	int		now;
	char	*temp;

	max = 0;
	now = 0;
	temp = NULL;
	while (map)
	{
		temp = ft_strtrim(map->line, "\n");
		now = ft_strlen(temp);
		if (max < now)
			max = now;
		free(temp);
		map = map->next;
	}
	return (max);
}

int	ft_add_in_map(char *line, t_map **map)
{
	if (!ft_characters_valid_map(line))
		return (0);
	if (ft_is_empty_str(line))
	{
		ft_putstr_fd("Error\nThere is a line in the middle of the map\n", 2);
		ft_free_map(map);
		return (0);
	}
	else
	{
		if (*map == NULL)
			*map = ft_new_map(ft_strtrim(line, "\n"));
		else
			ft_map_add_back(map, ft_new_map(ft_strtrim(line, "\n")));
	}
	return (1);
}

int	ft_fill_map(t_map **map, int fd)
{
	char	*line;

	line = ft_get_next_line(fd);
	while (line && ft_is_empty_str(line))
	{
		free(line);
		line = ft_get_next_line(fd);
	}
	while (line)
	{
		if (!ft_add_in_map(line, map))
		{
			free(line);
			return (0);
		}
		free(line);
		line = ft_get_next_line(fd);
	}
	return (1);
}
