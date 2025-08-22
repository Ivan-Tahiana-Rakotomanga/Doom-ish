/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_valid_extension.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fxu-lin <fxu-lin@student.42antananarivo.m  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/10 09:21:17 by fxu-lin           #+#    #+#             */
/*   Updated: 2025/06/11 13:49:22 by irakotom         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/header.h"

void	ft_display_error_extension(char *extension)
{
	ft_putstr_fd("Error\nInvalid file extension", 2);
	ft_putstr_fd(",it must end with '", 2);
	ft_putstr_fd(extension, 2);
	ft_putstr_fd("'\n", 2);
}

int	ft_valid_extension(char *file, char *extension)
{
	int	len_file;
	int	len_extension;

	len_file = ft_strlen(file) - 1;
	len_extension = ft_strlen(extension) - 1;
	while (file[len_file] && extension[len_extension])
	{
		if (extension[len_extension])
		{
			if (file[len_file] != extension[len_extension])
			{
				ft_display_error_extension(extension);
				return (0);
			}
		}
		len_file--;
		len_extension--;
	}
	if (file[len_file] == '\0' || file[len_file] == '/')
	{
		ft_display_error_extension(extension);
		return (0);
	}
	return (1);
}
