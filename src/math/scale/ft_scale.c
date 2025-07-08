#include "../../../includes/header.h"

double ft_coordinate_to_pixel(double value,double side)
{
	return (value * side);
}

double ft_pixel_to_coordinate(double value, double side)
{
	if (side == 0)
		return (0);
	return (floor(value / side));
}


