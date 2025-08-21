/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils_size_map.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irakotom <irakotom@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/29 10:12:39 by irakotom          #+#    #+#             */
/*   Updated: 2025/07/29 10:12:48 by irakotom         ###   ########.fr       */
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
