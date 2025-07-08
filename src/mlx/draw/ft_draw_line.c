#include "../../../includes/header.h"
#include <math.h>




void ft_draw_line(t_point start, t_point end,char *color, t_mlx *mlx)
{
	t_point increment;
	char *tmp_color;
	int steps;
	int i;

	i = 0;
    increment = ft_increment_dda(start, end);
	tmp_color = NULL;
	steps = fmax(fabs(end.x - start.x),fabs(end.y - start.y));

	printf("Ito ilay increment x %f \n", increment.y);

	while(i < steps)
	{
		tmp_color = ft_get_address((int) round(start.x), (int) round(start.y), mlx);
			*(unsigned int *) tmp_color = ft_convert_color(color);
		start.x = start.x + increment.x;
		start.y = start.y + increment.y;
		i++;
	}
}
