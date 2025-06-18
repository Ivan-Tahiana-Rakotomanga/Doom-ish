#include "../../../includes/header.h"

int	ft_get_limit_x(t_mlx *mlx)
{
	int	map_w;

	map_w = ft_map_width(mlx->map);
	return (mlx->width / map_w);
}

int	ft_get_limit_y(t_mlx *mlx)
{
	int	map_h;

	map_h = ft_map_height(mlx->map);
	return (mlx->height / map_h);
}

void	ft_get_limits_size(int *limit_x, int *limit_y, t_mlx *mlx)
{
	*limit_x = ft_get_limit_x(mlx);
	*limit_y = ft_get_limit_y(mlx);
}
