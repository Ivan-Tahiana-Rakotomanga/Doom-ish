/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exposed_file.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fxu-lin <fxu-lin@student.42antananarivo.m  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/18 10:25:10 by fxu-lin           #+#    #+#             */
/*   Updated: 2025/08/18 10:25:10 by fxu-lin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/header.h"

int	ft_exposed_file(char *file)
{
	int	len_file;
	int	i;

	i = 5;
	len_file = ft_strlen(file);
	while (i > 0)
	{
		len_file--;
		i--;
	}
	while (file[len_file] && file[len_file] != '/')
	{
		if (file[len_file] == '.')
		{
			ft_putstr_fd("Error\nThere is a hidden file", 2);
			return (0);
		}
		len_file--;
	}
	return (1);
}
