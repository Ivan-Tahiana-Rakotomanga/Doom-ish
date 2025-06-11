/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fxu-lin <fxu-lin@student.42antananari      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 11:40:49 by fxu-lin           #+#    #+#             */
/*   Updated: 2024/11/18 11:40:51 by fxu-lin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(char const *s, int c)
{
	int		i;
	char	*last_occurence;

	i = 0;
	last_occurence = NULL;
	while (s[i] != '\0')
	{
		if (s[i] == (char)c)
			last_occurence = (char *)&s[i];
		i++;
	}
	if ((char)c == '\0')
		return ((char *)&s[i]);
	return (last_occurence);
}
