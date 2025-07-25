#include "../../includes/header.h"

double ft_sub(double value, double value_two, int index)
{
	if(index == 0)
		return (value_two - value);
	else
		return (value - value_two);

}

double ft_get_x_text(t_point end, double side, int orient)
{
	double coordinate;
	double distance;

	coordinate = 0.0;
    if (orient< 2)
	{
      coordinate = ft_pixel_to_coordinate(end.x, side);
	  coordinate = coordinate + orient;
	  distance = ft_sub(ft_coordinate_to_pixel(coordinate, side), end.x, orient);
	}
	else 
    {
	  coordinate = ft_pixel_to_coordinate(end.y, side);
	  orient = orient - 2;
	  coordinate = coordinate + orient;
	  distance = ft_sub(ft_coordinate_to_pixel(coordinate, side), end.y, orient);
	}
	return (distance);
}
