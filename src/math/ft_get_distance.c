#include "../../includes/header.h"
double	ft_get_distance(t_point end, t_player player)
{
	double	x;
	double	y;

	x = end.x - player.x;
	x = x * x;
	y = end.y - player.y;
	y = y * y;
	return (sqrt(x) + sqrt(y));
}

