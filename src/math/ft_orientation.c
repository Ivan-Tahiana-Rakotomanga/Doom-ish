/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_orientation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irakotom <irakotom@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/29 10:20:51 by irakotom          #+#    #+#             */
/*   Updated: 2025/07/29 10:20:52 by irakotom         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

double	ft_orientation(int h_v, double angle)
{
	if (h_v == 2)
	{
		if ((0 <= angle && angle <= 90) || (270 <= angle && angle <= 360))
			return (2);
		else
			return (3);
	}
	else if (h_v == 1)
	{
		if (angle <= 180)
		{
			return (0);
		}
		else
			return (1);
	}
	return (0);
}
