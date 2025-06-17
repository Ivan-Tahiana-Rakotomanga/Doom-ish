/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_to_strs.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irakotom <irakotom@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 12:22:36 by irakotom          #+#    #+#             */
/*   Updated: 2025/06/17 16:08:38 by irakotom         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/header.h"

int	ft_fill_zero(int i, int width, char *res)
{
	while (i < width)
	{
		res[i] = '0';
		i++;
	}
	return (i);
}

char	*ft_fill_zero_line(char *line, int width)
{
	char	*res;
	int		i;

	i = 0;
	res = (char *)malloc((width) * sizeof(char));
	if (!res)
		return (NULL);
	while (line[i] && i < width)
	{
		if (ft_is_space(line[i]))
			res[i] = '0';
		else
			res[i] = line[i];
		i++;
	}
	i = ft_fill_zero(i, width, res);
	res[i] = '\0';
	return (res);
}

char	**ft_map_to_strs(t_map *map)
{
	int		heigth;
	int		width;
	char	**strs;
	int		i;

	i = 0;
	heigth = ft_get_height_map(map);
	width = ft_get_width_map(map);
	strs = (char **)malloc(sizeof(char *) * (heigth + 1));
	if (!strs)
		return (NULL);
	while (map)
	{
		strs[i] = ft_fill_zero_line(map->line, width);
		if (strs[i] == NULL)
		{
			ft_free_str(strs);
			return (NULL);
		}
		i++;
		map = map->next;
	}
	strs[i] = NULL;
	return (strs);
}
