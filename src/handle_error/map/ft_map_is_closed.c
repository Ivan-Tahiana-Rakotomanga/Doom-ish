
#include "../../../includes/header.h"



char	ft_find_start(int *start_x, int *start_y, char **map)
{
	int	j;
	int	i;
	int	width;
	int	height;

	j = 0;
	i = 0;
	width = ft_strlen(map[0]);
	height = ft_strs_len(map);
	while (i < height && *start_x == -1)
	{
		j = 0;
		while (j < width)
		{
			if (ft_is_orientation(map[i][j]))
			{
				*start_x = i;
				*start_y = j;
				return (map[i][j]);
			}
			j++;
		}
		i++;
	}
	return ('\0');
}

#include <stdio.h>

int ft_loop_close(int y, int x,char **map,int *w_h)
{
	if(map[y][x] == '1' || map[y][x] == ' ') 
		return (1);
	else if (map[y][x] == '0' || ft_is_orientation(map[y][x]))
	{
		if(!ft_valid_around(map,x,y,w_h))
		{
			ft_putstr_fd("Error\nThe map is not closed\n", 2);
			return(0);
		}
	}
	return (1);
}



int	ft_map_is_closed(char **map)
{
	int w_h[2];
	int x;
	int y;

	x = 0;
	y = 0;
	w_h[0] = ft_strlen(map[0]);
	w_h[1] = ft_strs_len(map);

	while(map[y])
	{
		x = 0;
		while(map[y][x])
		{
			if(!ft_loop_close(y, x, map, w_h))
				return (0);
			x++;
		}
		y++;
	}
	return (1);

}
