/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_duplicate_color.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fxu-lin <fxu-lin@student.42antananarivo.m  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/10 10:30:42 by fxu-lin           #+#    #+#             */
/*   Updated: 2025/06/11 14:07:22 by irakotom         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/header.h"

int	ft_is_duplicate_color(char *floor, char *ceiling)
{
	char	**colors_one;
	char	**colors_two;
	int		i;
	int		index;
	int		res;

	colors_one = ft_split(floor, ',');
	colors_two = ft_split(ceiling, ',');
	i = 0;
	index = 0;
	res = 0;
	while (colors_one[i])
	{
		if (ft_atoi(colors_one[i]) == ft_atoi(colors_two[i]))
			index++;
		i++;
	}
	if (index == 3)
	{
		ft_putstr_fd("Error\nFloor and ceiling colors must be different\n", 2);
		res = 1;
	}
	ft_free_str(colors_one);
	ft_free_str(colors_two);
	return (res);
}
