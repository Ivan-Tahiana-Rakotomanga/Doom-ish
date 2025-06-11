/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_empty_str.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irakotom <irakotom@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/11 12:45:53 by irakotom          #+#    #+#             */
/*   Updated: 2025/06/11 12:55:55 by irakotom         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/header.h"

int	ft_is_empty_str(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (!ft_is_space(str[i]))
			return (0);
		i++;
	}
	return (1);
}
