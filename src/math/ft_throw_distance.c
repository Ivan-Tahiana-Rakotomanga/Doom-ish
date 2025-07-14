#include "../../includes/header.h"

double ft_throw_distance(double width_screen, double angle_fov)
{
	double half_fov;
	double half_screen;

	half_screen = width_screen / 2;
	half_fov = angle_fov / 2;

	if (half_fov == 0.0)
		return (0);
	return (half_screen / half_fov);
}
