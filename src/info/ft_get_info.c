/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_info.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irakotom <irakotom@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/23 16:59:52 by irakotom          #+#    #+#             */
/*   Updated: 2025/07/23 18:24:22 by irakotom         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/header.h"

int	ft_len_re(char *str)
{
	int	i;
	int	count;

	i = 1;
	count = 0;
	while (str[i])
	{
		if (!ft_is_space(str[i]))
			count++;
		i++;
	}
	return (count);
}

char	*ft_remove_space_cf(char *str)
{
	int		len;
	char	*res;
	int		i;
	int		j;

	len = ft_len_re(str);
	res = malloc(sizeof(char) * (len + 1));
	if (!res)
		return (NULL);
	i = 1;
	j = 0;
	while (str[i])
	{
		if (!ft_is_space(str[i]))
		{
			res[j] = str[i];
			j++;
		}
		i++;
	}
	res[j] = '\0';
	return (res);
}

void	ft_set_utils(char *line, t_utils *utils)
{
	int		value;
	char	**lines;
	char	*temp_lines;

	temp_lines = ft_strtrim(line, " \n");
	lines = ft_split(temp_lines, ' ');
	value = ft_index_id(lines[0]);
	if (value == 1)
		utils->no = ft_strdup(lines[1]);
	else if (value == 2)
		utils->so = ft_strdup(lines[1]);
	else if (value == 3)
		utils->ea = ft_strdup(lines[1]);
	else if (value == 4)
		utils->we = ft_strdup(lines[1]);
	else if (value == 5)
	{
		utils->c = ft_convert_color(ft_remove_space_cf(temp_lines));
	}
	else if (value == 6)
		utils->f = ft_convert_color(ft_remove_space_cf(temp_lines));
	ft_free_str(lines);
	free(temp_lines);
}

void	ft_get_info(char *file, t_utils *utils)
{
	char	*line;
	int		fd;
	int		i;

	fd = open(file, O_RDONLY);
	line = ft_get_next_line(fd);
	i = 0;
	while (line && i < 6)
	{
		if (!ft_is_empty_str(line))
		{
			ft_set_utils(line, utils);
		    i++;
		}
		free(line);
		line = ft_get_next_line(fd);
	}
	free(line);
	close(fd);
}
