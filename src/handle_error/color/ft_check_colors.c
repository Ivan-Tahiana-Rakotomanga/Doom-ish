/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_colors.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irakotom <irakotom@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/11 13:05:46 by irakotom          #+#    #+#             */
/*   Updated: 2025/08/12 18:10:45 by irakotom         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/header.h"

int	ft_res_loop(char **colors)
{
	int	temp_color;
	int	i;

	i = 0;
	temp_color = 0;
	while (colors[i])
	{
		if (!ft_is_valid_number(colors[i]) || ft_is_empty_str(colors[i]))
		{
			ft_putstr_fd("Error\nColor values must be positive numbers not:",
				2);
			ft_putstr_fd(colors[i], 2);
			ft_putstr_fd("\n", 2);
			return (0);
		}
		else
		{
			temp_color = ft_atoi(colors[i]);
			if (!ft_valid_color(temp_color, colors[i]))
				return (0);
		}
		i++;
	}
	return (1);
}

int	ft_nbr_c(char *color)
{
	int	count;
	int	i;

	i = 0;
	count = 0;
	while (color[i])
	{
		if (color[i] == ',')
			count++;
		i++;
	}
	if (count != 2)
		return (0);
	else
		return (1);
}

int	ft_error_format(char *temp, char **colors)
{
	ft_putstr_fd("Error\nInvalid color format ", 2);
	ft_putstr_fd("it must be three digits separated by a comma not ", 2);
	ft_putstr_fd(temp, 2);
	ft_putstr_fd(" \n", 2);
	free(temp);
	ft_free_str(colors);
	return (0);
}

int	ft_check_colors(char *color)
{
	char	**colors;
	char	*temp;
	int		res;

	res = 0;
	temp = ft_strtrim(color, " \n");
	colors = NULL;
	if (ft_is_empty_str(temp))
	{
		ft_putstr_fd("Error\nMissing color \n", 2);
		free(temp);
		return (0);
	}
	colors = ft_split(temp, ',');
	if (colors == NULL || !ft_nbr_c(color) || ft_strs_len(colors) != 3)
		return (ft_error_format(temp, colors));
	res = ft_res_loop(colors);
	free(temp);
	ft_free_str(colors);
	return (res);
}
