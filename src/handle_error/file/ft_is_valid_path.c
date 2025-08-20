/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_valid_path.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irakotom <irakotom@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/11 13:39:48 by irakotom          #+#    #+#             */
/*   Updated: 2025/06/11 13:45:06 by irakotom         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../../../includes/header.h"

int	ft_is_valid_path(char *path, char *extension)
{
	if (!ft_exposed_file(path))
		return (0);
	if (!ft_valid_file(path))
		return (0);
	else if (!ft_valid_extension(path, extension))
		return (0);
	return (1);
}
