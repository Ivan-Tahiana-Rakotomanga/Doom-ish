
long ft_atoi_long(const char *str)
{
	long result;
	long sign;
	long i;

	result = 0;
	sign = 1;
	i = 0;
	while (str[i] == ' ' || (str[i] >= '\t' && str[i] <= '\r'))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = result * 10 + (str[i] - '0');
		i++;
	}
	return (result * sign);
}

int ft_over_int_max(const char *str)
{
	long res;

	res = ft_atoi_long(str);

	if( 2147483647 <  res)
		return (1);
	return (0);
}
