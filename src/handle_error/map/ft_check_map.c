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

int	ft_have_space_btw_map(char *line, int i)
{
	while (line[i] && ft_is_space(line[i]))
		i++;
	if (line[i])
	{
		ft_putstr_fd("Error\nThere is one or more spaces ", 2);
		ft_putstr_fd("in the middle of the map\n", 2);
		return (0);
	}
	else
		return (1);
}

int	ft_check_per_line_map(char *line, int *orientation)
{
	int	i;

	i = 0;
	while (line[i] && ft_is_space(line[i]))
		i++;
	while (line[i])
	{
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
		ft_putstr_fd("Error\nThere is no player or no map\n", 2);
		return (0);
	}
	else if (orientation > 1)
	{
		ft_putstr_fd("Error\nThere are more than one player in the map\n", 2);
		return (0);
	}
	return (1);
}
