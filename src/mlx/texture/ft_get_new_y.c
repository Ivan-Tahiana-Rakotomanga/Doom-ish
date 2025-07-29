/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_new_y.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fxu-lin <fxu-lin@student.42antananarivo.m  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/29 15:38:24 by fxu-lin           #+#    #+#             */
/*   Updated: 2025/07/29 15:38:26 by fxu-lin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

double	ft_get_percent(double value, double max)
{
	return (value * 100 / max);
}

int	ft_get_y_percent(double percent, double height_img)
{
	return ((int)(percent * height_img) / 100);
}

int	ft_get_new_y(double value, double height_wall, double height_img)
{
	double	percent;
	int		res;

	percent = ft_get_percent(value, height_wall);
	res = ft_get_y_percent(percent, height_img);
	return (res);
}
