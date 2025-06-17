/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_many_args_line.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fxu-lin <fxu-lin@student.42antananarivo.m  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 08:26:53 by fxu-lin           #+#    #+#             */
/*   Updated: 2025/06/17 08:26:53 by fxu-lin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/header.h"

int	ft_many_args_line(char **lines)
{
	if (ft_strs_len(lines) != 2)
	{
		ft_putstr_fd("Error\n Many arguments in one line in texture or color\n",
			2);
		return (1);
	}
	return (0);
}
