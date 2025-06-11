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
	char **colors_one;
	char **colors_two;
	int i;
	int index;

	colors_one = ft_split(floor, ',');
	colors_two = ft_split(ceiling, ',');
	i = 0;
	index = 0;

	while(colors_one[i])
	{
		if(ft_strcmp(colors_one[i], colors_two[i]) == 0)
			index++;
		i++;
	}
	if (index == 3)
	{
		ft_putstr_fd("Error\nFloor and ceiling colors must be different", 2);
	    return (1);
	}
	return (0);
}
