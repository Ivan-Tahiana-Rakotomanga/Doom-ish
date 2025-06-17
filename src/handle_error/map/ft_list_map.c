/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irakotom <irakotom@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 09:27:11 by irakotom          #+#    #+#             */
/*   Updated: 2025/06/17 10:01:49 by irakotom         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/header.h"

t_map	*ft_new_map(char *line)
{
	t_map	*map;

	map = malloc(sizeof(t_map));
	map->line = line;
	map->next = NULL;
	return (map);
}

t_map	*ft_last_map(t_map *map)
{
	while (map)
	{
		if (!map->next)
			return (map);
		map = map->next;
	}
	return (map);
}

void	ft_map_add_back(t_map **map, t_map *new_end_map)
{
	t_map	*last;

	last = ft_last_map(*map);
	last->next = new_end_map;
	new_end_map->next = NULL;
}

void	ft_free_map(t_map **map)
{
	t_map	*temp;

	while (*map)
	{
		temp = (*map)->next;
		free((*map)->line);
		(*map)->line = NULL;
		free(*map);
		*map = NULL;
		*map = temp;
	}
}
