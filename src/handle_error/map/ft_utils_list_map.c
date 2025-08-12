/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils_list_map.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irakotom <irakotom@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 10:14:52 by irakotom          #+#    #+#             */
/*   Updated: 2025/08/12 17:56:40 by irakotom         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/header.h"

int	ft_add_in_map(char *line, t_map **map)
{
	if (!ft_characters_valid_map(line))
	{
		ft_free_map(map);
		free(line);
		return (0);
	}
	if (*map == NULL)
		*map = ft_new_map(ft_strtrim(line, "\n"));
	else
		ft_map_add_back(map, ft_new_map(ft_strtrim(line, "\n")));
	return (1);
}

void	ft_free_next(char **line, int fd)
{
	free(*line);
	*line = ft_get_next_line(fd);
}

int	ft_middle_map(char **line, int fd, t_map **map)
{
	ft_free_next(line, fd);
	while (*line)
	{
		if (!ft_is_empty_str(*line))
		{
			ft_putstr_fd("Error\nThere is a line ", 2);
			ft_putstr_fd("in the middle of the map or ", 2);
			ft_putstr_fd("too much configurations\n", 2);
			free(*line);
			ft_free_map(map);
			return (0);
		}
		ft_free_next(line, fd);
	}
	free(*line);
	return (1);
}

int	ft_fill_map(t_map **map, int fd)
{
	char	*line;

	line = ft_get_next_line(fd);
	while (line && ft_is_empty_str(line))
		ft_free_next(&line, fd);
	while (line && !ft_is_empty_str(line))
	{
		if (!ft_add_in_map(line, map))
			return (0);
		ft_free_next(&line, fd);
	}
	return (ft_middle_map(&line, fd, map));
}
