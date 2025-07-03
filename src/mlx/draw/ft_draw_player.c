#include "../../../includes/header.h"


void ft_draw_player(t_point a, int size, char *color, t_mlx *mlx)
{
	int x;
	int y;
	int tmp_x;
	char *tmp_color;
	int size_xy[2];

	x = a.x * mlx->side + (mlx->side /2);
	y = a.y * mlx->side + (mlx->side /2);
	tmp_color = NULL;

	size_xy[0] = x + size;
	size_xy[1] = y + size;
	tmp_x = x;

	while(y < size_xy[1])
	{
		x = tmp_x;
		while(x < size_xy[0])
		{
			tmp_color = ft_get_address(x, y, mlx);
			*(unsigned int *) tmp_color = ft_convert_color(color);
			x++;
		}
		y++;
	}
	

}
