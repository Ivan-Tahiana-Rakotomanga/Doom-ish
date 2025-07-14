#include "../../includes/header.h"
int	ft_on_screen(double x, double y, t_mlx mlx)
{
	if (x < 0 || mlx.width <= x)
		return (0);
	if (y < 0 || mlx.height <= y)
		return (0);
	return (1);
}

