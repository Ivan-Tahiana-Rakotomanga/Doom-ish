/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils_check_file.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fxu-lin <fxu-lin@student.42antananarivo.m  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 08:26:57 by fxu-lin           #+#    #+#             */
/*   Updated: 2025/06/17 08:26:57 by fxu-lin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/header.h"

char	*ft_first_line(int fd)
{
	char	*line;

	line = ft_get_next_line(fd);
	if (!line)
	{
		ft_putstr_fd("Error\n This file is empty\n", 2);
		return (NULL);
	}
	return (line);
}

int	ft_check_color_part(char **one, char **two, char *line)
{
	char	*temp_line;

	temp_line = line;
	temp_line++;
	if (!ft_check_colors(temp_line))
		return (0);
	if (!*one)
		*one = ft_strdup(temp_line);
	else if (!*two)
		*two = ft_strdup(temp_line);
	return (1);
}

int	ft_is_valid_argument_textures(char **strs, char *line)
{
	if (ft_strs_len(strs) != 2)
	{
		ft_putstr_fd("Error\nThe has too much ", 2);
		ft_putstr_fd("argument for the texture part in: '", 2);
		ft_putstr_fd(line, 2);
		ft_putstr_fd("' \n", 2);
		return (0);
	}
	return (1);
}

int	ft_handle_index_id(char *line, char **one, char **two)
{
	int		value;
	char	**lines;
	char	*temp_lines;

	temp_lines = ft_strtrim(line, " \n");
	lines = ft_split(temp_lines, ' ');
	value = ft_index_id(lines[0]);
	if (value == 0)
		return (ft_free_str(lines), free(temp_lines), 0);
	if (value < 5)
	{
		if (!ft_valid_file(lines[1]) || !ft_is_valid_argument_textures(lines,
				temp_lines))
			return (free(temp_lines), ft_free_str(lines), 0);
		free(temp_lines);
	}
	else if (value > 4)
	{
		free(temp_lines);
		if (!ft_check_color_part(one, two, line))
			return (ft_free_str(lines), 0);
	}
	return (ft_free_str(lines), value);
}
