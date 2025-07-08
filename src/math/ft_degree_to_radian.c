#include "../../includes/header.h"

double ft_degree_to_radian(double degree)
{
	double radian;
	double pi;

	pi = 3.14159265358979323846;
	radian =  degree * ( pi /180.0);

	if (radian < 0)
		radian += 2 * pi;

	return (radian);
}
