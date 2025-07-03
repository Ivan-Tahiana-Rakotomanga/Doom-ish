#include "../../../includes/header.h"

int	ft_size_case_x(t_mlx *mlx)
{
	int	map_w;

	map_w = ft_map_width(mlx->map);
	return (mlx->width / map_w);
}

int	ft_size_case_y(t_mlx *mlx)
{
	int	map_h;

	map_h = ft_map_height(mlx->map);
	return (mlx->height / map_h);
}

void	ft_size_cases(int *case_x, int *case_y, t_mlx *mlx)
{
	*case_x = ft_size_case_x(mlx);
	*case_y = ft_size_case_y(mlx);
}
