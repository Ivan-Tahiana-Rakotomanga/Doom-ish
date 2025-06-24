#include "../../includes/header.h"
#include <math.h>

double	ft_delta(double a, double b)
{
	return (b - a);
}

double	ft_step(double delta_x, double delta_y)
{
	if (delta_x > delta_y)
		return (delta_x);
	else
		return (delta_y);
}

t_point	ft_increment_dda(t_point a, t_point b)
{
	t_point	increment;
	double	step;
	double	delta_x;
	double	delta_y;

	increment.x = 0.0;
	increment.y = 0.0;
	delta_x = ft_delta(a.x, b.x);
	delta_y = ft_delta(a.y, b.y);
	step = ft_step(delta_x, delta_y);
	increment.x = delta_x / step;
	increment.y = delta_y / step;
	return (increment);
}

/*void ft_print_point(t_point increment, t_point a, t_point b)
{
	t_point	d;

	d.x = a.x;
	d.y = a.y;
	while(d.x < b.x || d.y < b.y)
	{
		printf("x=%f |  y=%f\n",round(d.x), round(d.y));
		printf("______________\n");
		d.x = d.x + increment.x;
		d.y = d.y + increment.y;
	}
}

int	main(void)
{
	t_point a;
	a.x = 5;
	a.y = 7;
	t_point b;
	b.x = 10;
	b.y = 15;

	t_point increment = ft_increment_dda(a, b);
	ft_print_point(increment, a, b);

	return (0);

}*/
