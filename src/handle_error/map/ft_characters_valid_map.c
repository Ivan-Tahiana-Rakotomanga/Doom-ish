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
	return (c == '\n' || c == ' ' || ft_is_orientation(c) || c == '0'
		|| c == '1');
}

int	ft_character_not_valid(char c)
{
	ft_putstr_fd("Error\nThis character is not valid for the map: ", 2);
	write(2, &c, 1);
	ft_putstr_fd("\n", 2);
	return (0);
}

int	ft_space_btw(void)
{
	ft_putstr_fd("Error\nThe map is not closed\n", 2);
	return (0);
}

int	ft_valid_btw(char *line, int len, int i)
{
	char	c;

	c = 0;
	if (line[i] == ' ')
	{
		if (0 < i - 1 && line[i - 1] == '0')
		{
			while (i + 1 < len)
			{
				c = line[i + 1];
				if (c == ' ')
					i++;
				else if (c == '0')
					return (ft_space_btw());
				else
					return (1);
			}
		}
	}
	return (1);
}

int	ft_characters_valid_map(char *line)
{
	int		i;
	char	c;
	int		len;

	len = ft_strlen(line);
	i = 0;
	c = 0;
	while (line[i])
	{
		c = line[i];
		if (!ft_valid_btw(line, len, i))
			return (0);
		if (!ft_character_valid(c))
			return (ft_character_not_valid(c));
		i++;
	}
	return (1);
}
