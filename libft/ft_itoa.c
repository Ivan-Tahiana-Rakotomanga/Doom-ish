/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irakotom <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 08:03:34 by irakotom          #+#    #+#             */
/*   Updated: 2024/03/09 09:40:22 by irakotom         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_get_number_lenght(int nb)
{
	int	lenght;

	if (nb <= 0)
		lenght = 1;
	else
		lenght = 0;
	while (nb != 0)
	{
		nb = nb / 10;
		lenght++;
	}
	return (lenght);
}

void	ft_fill_itoa_str(char *str, int nb, int lenght)
{
	str[lenght] = '\0';
	lenght--;
	if (nb == 0)
		str[lenght] = '0';
	while (nb != 0)
	{
		str[lenght] = nb % 10 + '0';
		nb = nb / 10;
		lenght--;
	}
}

char	*ft_itoa(int n)
{
	char	*str;
	int		lenght;

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	lenght = ft_get_number_lenght(n);
	str = (char *)malloc((lenght + 1) * sizeof(char));
	if (!str)
		return (NULL);
	if (n < 0)
	{
		str[0] = '-';
		n = -n;
	}
	ft_fill_itoa_str(str, n, lenght);
	return (str);
}
