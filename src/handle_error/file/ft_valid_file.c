/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_valid_file.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fxu-lin <fxu-lin@student.42antananarivo.m  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/10 08:40:45 by fxu-lin           #+#    #+#             */
/*   Updated: 2025/06/11 13:51:28 by irakotom         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/header.h"

int	ft_valid_file(char *file)
{
	if (access(file, F_OK) != 0)
	{
		ft_putstr_fd("Error\nNo such file or directory: ", 2);
		ft_putstr_fd(file, 2);
		ft_putstr_fd("\n", 2);
		return (0);
	}
	if (access(file, R_OK) != 0)
	{
		ft_putstr_fd("Error\nPermission denied: ", 2);
		ft_putstr_fd(file, 2);
		ft_putstr_fd("\n", 2);
		return (0);
	}
	return (1);
}
