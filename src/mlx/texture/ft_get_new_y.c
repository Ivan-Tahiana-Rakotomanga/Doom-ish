double	ft_get_percent(double value, double max)
{
	return (value * 100 / max);
}

int	ft_get_y_percent(double percent, double height_img)
{
	return ((int)(percent * height_img) / 100);
}

int	ft_get_new_y(double value, double height_wall, double height_img)
{
	double	percent;
	int		res;

	percent = ft_get_percent(value, height_wall);
	res = ft_get_y_percent(percent, height_img);
	return (res);
}
