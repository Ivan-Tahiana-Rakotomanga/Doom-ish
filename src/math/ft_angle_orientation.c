/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_angle_orientation.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irakotom <irakotom@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/29 10:20:36 by irakotom          #+#    #+#             */
/*   Updated: 2025/07/29 10:20:36 by irakotom         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

double	ft_angle_orientation(char c)
{
	if (c == 'N')
		return (270);
	else if (c == 'S')
		return (90);
	else if (c == 'E')
		return (0);
	else if (c == 'W')
		return (180);
	return (0);
}
