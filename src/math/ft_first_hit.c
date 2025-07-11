#include "../../includes/header.h"


double ft_first_hit_vy(double y_pixel, double side, double angle)
{
	double res;

	res = 0.0;
	if (angle < 180)
		res = (ft_pixel_to_coordinate(y_pixel, side) * side) - 1;
	else 
		res = (ft_pixel_to_coordinate(y_pixel, side) * side) + side;
	return (res);
}

double ft_first_hit_vx(t_player player, double angle, double y_pixel)
{
	double res;
	res = (y_pixel - player.y) / tan(ft_degree_to_radian(angle)) + player.x;
    return (res);
}


double ft_first_hit_hx(double x_pixel, double side, double angle)
{
	double res;

	res = 0.0;

	if(90 < angle && angle < 270)
		res = (ft_pixel_to_coordinate(x_pixel, side) * side) + side;
	else
		res = (ft_pixel_to_coordinate(x_pixel, side) * side) - 1;
	return (res);
}

double ft_first_hit_hy(t_player player, double angle, double x_pixel)
{
	double res;

	res = player.y + (player.x - x_pixel) * tan(ft_degree_to_radian(angle));

	return (res);
}



