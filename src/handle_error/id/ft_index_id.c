/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_index_id.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irakotom <irakotom@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/11 12:32:33 by irakotom          #+#    #+#             */
/*   Updated: 2025/06/11 12:45:32 by irakotom         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/header.h"

int	ft_index_id(char *id)
{
	if (ft_strcmp(id, "NO") == 0)
		return (1);
	else if (ft_strcmp(id, "SO") == 0)
		return (2);
	else if (ft_strcmp(id, "WE") == 0)
		return (3);
	else if (ft_strcmp(id, "EA") == 0)
		return (4);
	else if (ft_strcmp(id, "C") == 0)
		return (5);
	else if (ft_strcmp(id, "F") == 0)
		return (6);
	ft_putstr_fd("Error\nInvalid identifier\n", 2);
	return (0);
}
