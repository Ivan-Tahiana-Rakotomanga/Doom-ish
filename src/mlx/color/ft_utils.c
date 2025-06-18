#include "../../../includes/header.h"

int	ft_map_height(char **map)
{
	int	i;

	i = 0;
	while (map[i])
		i++;
	return (i);
}

int	ft_map_width(char **map)
{
	int	i;
	int	max;
	int	len;

	i = 0;
	max = 0;
	while (map[i])
	{
		len = 0;
		while (map[i][len])
			len++;
		if (len > max)
			max = len;
		i++;
	}
	return (max);
}
