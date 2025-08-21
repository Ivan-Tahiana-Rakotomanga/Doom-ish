#include "../../../includes/header.h"

int	ft_is_one(char c)
{
	if (c == '1')
		return (1);
	else if (c == '0')
		return (1);
	else if (ft_is_orientation(c))
		return (1);
	else
		return (0);
}

int	ft_valid_around(char **map, int x, int y, int *w_h)
{
	int	res;

	res = 0;
	if (x <= 0 || y <= 0 || w_h[0] <= x || w_h[1] <= y)
		return (0);
	res = ft_is_one(map[y][x - 1]) + ft_is_one(map[y][x + 1]);
	res = res + ft_is_one(map[y - 1][x]) + ft_is_one(map[y + 1][x]);
	if (res != 4)
		return (0);
	return (1);
}
