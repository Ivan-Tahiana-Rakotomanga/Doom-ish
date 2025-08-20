/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_next_line.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fxu-lin <fxu-lin@student.42antananarivo.m  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 08:27:10 by fxu-lin           #+#    #+#             */
/*   Updated: 2025/06/17 08:27:10 by fxu-lin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/header.h"

int	ft_error_fd(int fd)
{
	if (fd < 0)
	{
		ft_putstr_fd("Error\nInvalid file descriptor\n", 2);
		return (1);
	}
	return (0);
}

char	*ft_strjoin_char(char *line, char c)
{
	int		len;
	char	*new;
	int		i;

	len = 0;
	i = 0;
	while (line && line[len])
		len++;
	new = malloc(len + 2);
	if (!new)
		return (NULL);
	while (i < len)
	{
		new[i] = line[i];
		i++;
	}
	new[i] = c;
	i++;
	new[i] = '\0';
	free(line);
	return (new);
}

char	*ft_get_next_line(int fd)
{
	char	*line;
	char	c;
	int		r;

	if (ft_error_fd(fd))
		return (NULL);
	line = NULL;
	r = read(fd, &c, 1);
	while (r > 0)
	{
		line = ft_strjoin_char(line, c);
		if (!line)
			return (NULL);
		if (c == '\n')
			break ;
		r = read(fd, &c, 1);
	}
	if (r <= 0 && (!line || line[0] == '\0'))
	{
    ft_putstr_fd("Error\nThe file is empty\n", 2);
		free(line);
		return (NULL);
	}
	return (line);
}
