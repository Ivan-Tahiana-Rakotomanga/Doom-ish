#include "../../../includes/header.h"

void	ft_add_color_pixels(t_mlx *mlx, char c)
{
	if (c == '1')
		mlx->color = (255 << 16) | (0 << 8) | (0);
	else
		mlx->color = (0 << 16) | (255 << 8) | (0);
}
