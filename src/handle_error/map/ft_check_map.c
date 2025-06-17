/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irakotom <irakotom@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 13:43:59 by irakotom          #+#    #+#             */
/*   Updated: 2025/06/17 15:03:11 by irakotom         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/header.h"

int	ft_have_space_btw_map(char *line, int i, int len)
{
	int	before;
	int	after;

	before = i - 1;
	after = i + 1;
	if (i > 0 && i < len)
	{
	printf("tonga ato line=%s ny c = %c %c\n",line, line[before], line[after]);
		if (!ft_is_space(line[before]) && !ft_is_space(line[after]))
		{
			if (ft_character_valid(line[before]) && ft_character_valid(line[after]))
			{
				ft_putstr_fd("Error\nThere is an empty space ", 2);
				ft_putstr_fd("in the middle of the map\n", 2);
				return (1);
			}
		}
	}
	return (0);
}

int	ft_check_per_line_map(char *line, int *orientation)
{
	int	len;
	int	i;

	len = ft_strlen(line);
	i = 0;
	while (line[i])
	{
		if (ft_is_space(line[i]) && ft_have_space_btw_map(line, i, len))
			return (0);
		if (ft_is_orientation(line[i]))
			(*orientation)++;
		i++;
	}
	return (1);
}

int	ft_check_under_map(t_map *map)
{
	int	orientation;

	orientation = 0;
	while (map)
	{
		if (!ft_check_per_line_map(map->line, &orientation))
			return (0);
		map = map->next;
	}
	if (orientation == 0)
	{
		ft_putstr_fd("Error\nThere is no player in the map\n", 2);
		return (0);
	}
	else if (orientation > 1)
	{
		ft_putstr_fd("Error\nThere is more than one player on the map\n", 2);
		return (0);
	}
	return (1);
}
