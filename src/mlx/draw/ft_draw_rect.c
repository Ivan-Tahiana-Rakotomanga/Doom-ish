#include "../../../includes/header.h"

void	ft_draw_rect(t_point a, t_point b, char *color, t_mlx *mlx)
{
	double	x;
	double	y;
	char	*tmp_color;
	double	tmp_x;

	x = a.x;
	y = a.y;
	tmp_x = x;
	tmp_color = NULL;
	
	while (y < b.y)
	{
		x = tmp_x;
		while (x < b.x)
		{
			tmp_color = ft_get_address(x, y, mlx);
			*(unsigned int *)tmp_color = ft_convert_color(color);
			x++;
		}
		y++;
	}
}
