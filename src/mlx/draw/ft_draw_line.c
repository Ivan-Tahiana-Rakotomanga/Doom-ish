#include "../../../includes/header.h"

void ft_draw_line(t_point start, t_point end,char *color, t_mlx *mlx)
{
	t_point increment;
	char *tmp_color;

    increment = ft_increment_dda(start, end);
	tmp_color = NULL;

	while(start.x != end.x && start.y != end.y )
	{
		start.x = start.x + increment.x;
		start.y = start.y + increment.y;
		tmp_color = ft_get_address(start.x, start.y, mlx);
			*(unsigned int *) tmp_color = ft_convert_color(color);
	}


}

