/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_characters_valid_map.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irakotom <irakotom@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 11:06:16 by irakotom          #+#    #+#             */
/*   Updated: 2025/06/17 12:42:40 by irakotom         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/header.h"

int	ft_character_valid(char c)
{
	return (ft_is_space(c) || ft_is_orientation(c) || c == '0' || c == '1');
}

int	ft_characters_valid_map(char *line)
{
	int		i;
	char	c;

	i = 0;
	c = 0;
	while (line[i])
	{
		c = line[i];
		if (!ft_character_valid(c))
		{
			ft_putstr_fd("Error\nThis character is not valid for the map: ", 2);
			write(2, &c, 1);
			ft_putstr_fd("\n", 2);
			return (0);
		}
		i++;
	}
	return (1);
}
