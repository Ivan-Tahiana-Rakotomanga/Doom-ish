/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format_map_is_valid.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fxu-lin <fxu-lin@student.42antananarivo.m  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/10 10:41:08 by fxu-lin           #+#    #+#             */
/*   Updated: 2025/06/10 10:41:08 by fxu-lin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/header.h"

int	ft_is_orientation(char c)
{
	if (c == 'N' || c == 'S' || c == 'W' || c == 'E')
		return (1);
	return (0);
}

int	ft_is_format_map(char c)
{
	if (c == '1' || c == '0' || ft_is_orientation(c))
		return (1);
	ft_putstr_fd("Error\nFormat map invalid\n", 2);
	return (0);
}

int	ft_have_error_in_map(int *orientation, char **map, int i, int j)
{
	if (*orientation > 1)
	{
		ft_putstr_fd("Error\nThere is more than", 2);
		ft_putstr_fd(" one orientation in map\n", 2);
		return (1);
	}
	if (!ft_is_format_map(map[i][j]))
		return (1);
	else if (ft_is_orientation(map[i][j]))
		(*orientation)++;
	return (0);
}

int	ft_format_map_is_valid(char **map)
{
	int	i;
	int	j;
	int	index_orientation;

	i = 0;
	index_orientation = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (ft_have_error_in_map(&index_orientation, map, i, j))
				return (0);
			j++;
		}
		i++;
	}
	if (index_orientation == 0)
		ft_putstr_fd("Error\nIt must have at least one orientation in map\n",
			2);
	return (1);
}
