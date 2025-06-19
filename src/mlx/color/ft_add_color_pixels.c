#include "../../../includes/header.h"

void	ft_add_color_pixels(t_mlx *mlx,int i, int j)
{
  char **map;

  map = mlx->map;

  if(mlx->x_player == i && mlx->y_player == j)
    mlx->color = (0 << 16) | (0 << 8) | (255);
  else if (map[i][j] == '1')
		mlx->color = (255 << 16) | (0 << 8) | (0);
	else
		mlx->color = (0 << 16) | (255 << 8) | (0);
}
