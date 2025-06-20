#include "../../../includes/header.h"

void	ft_add_color_pixels(t_mlx *mlx,int i, int j)
{
  char **map;

  map = mlx->map;

  if(mlx->x_player == i && mlx->y_player == j)
    mlx->color = ft_convert_color("0,0,255");
  else if (map[i][j] == '1')
		mlx->color = ft_convert_color("255,0,0");
	else
		mlx->color = ft_convert_color("0,255,0");
}
