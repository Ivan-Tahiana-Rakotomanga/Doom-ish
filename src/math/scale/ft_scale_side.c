#include "../../../includes/header.h"

void	ft_scale_side(char **map, t_mlx *mlx)
{
	double	width;
	double	height;
	double	max;

	width = ft_strlen(map[0]);
	height = ft_strs_len(map);
	max = fmin(width, height);
	if (max < 600)
		mlx->side = (int)ceil(600 / max);
	else
		mlx->side = (int)ceil(max / 600);
}
