/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_valid_extension.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fxu-lin <fxu-lin@student.42antananarivo.m  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/10 09:21:17 by fxu-lin           #+#    #+#             */
/*   Updated: 2025/06/10 09:21:17 by fxu-lin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/header.h"

int	ft_valid_extension(char *file, char *extension)
{
	int	len_file;
	int	len_extension;

	len_file = ft_strlen(file);
	len_extension = ft_strlen(extension);
	len_file--;
	len_extension--;
	while (file[len_file] && extension[len_extension])
	{
		if (extension[len_extension])
		{
			if (file[len_file] != extension[len_extension])
			{
				ft_putstr_fd("Error\nInvalid file extension\n", 2);
				return (0);
			}
		}
		len_file--;
		len_extension--;
	}
	return (1);
}
