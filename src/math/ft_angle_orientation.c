double ft_angle_orientation(char c)
{
	if(c == 'N')
		return (270);
	else if (c == 'S')
		return (90);
	else if (c == 'E')
		return (0);
	else if (c == 'W')
		return (180);
	return (0);
}
