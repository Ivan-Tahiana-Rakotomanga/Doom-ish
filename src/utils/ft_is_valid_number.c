/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_valid_number.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irakotom <irakotom@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/11 13:01:14 by irakotom          #+#    #+#             */
/*   Updated: 2025/06/11 13:04:55 by irakotom         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/header.h"

int	ft_is_valid_number(char *nbr)
{
	int	i;

	i = 0;
	while (nbr[i] && ft_is_space(nbr[i]))
		i++;
	if (nbr[i] == '-' || nbr[i] == '+')
		i++;
	while (nbr[i])
	{
		if (!ft_isdigit(nbr[i]) && !ft_is_space(nbr[i]))
		{
			return (0);
		}
		i++;
	}
	return (1);
}
