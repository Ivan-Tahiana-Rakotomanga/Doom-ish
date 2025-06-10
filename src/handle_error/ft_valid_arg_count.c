/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_valid_arg_count.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fxu-lin <fxu-lin@student.42antananarivo.m  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/10 08:35:08 by fxu-lin           #+#    #+#             */
/*   Updated: 2025/06/10 08:37:07 by fxu-lin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/header.h"

int	ft_valid_arg_count(int argc)
{
	if (argc != 2)
	{
		ft_putstr_fd("Error\nIt must be one argument\n", 2);
		return (0);
	}
	return (1);
}
