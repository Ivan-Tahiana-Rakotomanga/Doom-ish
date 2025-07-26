double	ft_orientation(int h_v, double angle)
{
	if (h_v == 2)
	{
		if ((0 <= angle && angle <= 90) || (270 <= angle && angle <= 360))
			return (2);
		else
			return (3);
	}
	else if (h_v == 1)
	{
		if (angle <= 180)
		{
			return (0);
		}
		else
			return (1);
	}
	return (0);
}
