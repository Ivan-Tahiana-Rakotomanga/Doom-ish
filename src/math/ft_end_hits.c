#include "../../includes/header.h"

double ft_get_ya(double angle, double side, int index)
{
	if(index == 1)
	{
		if (angle < 180)
			return(side);
		return (-side);
	}
	else
	{
	  if(90 <= angle && angle <= 270)
			return (side);
	  else
	       return (-side);
	}
}


int ft_on_screen(t_point end,t_mlx mlx)
{
	if(end.x < 0 && mlx.width < end.x)
		return (0);
	if(end.y < 0 && mlx.height < end.y)
		return (0);
	return (1);
}


t_point ft_end_hit_h(t_player player, t_mlx mlx, double y_pixel)
{
	t_point end;
	double ya;
	double xa;
	
	end.y =  ft_first_hit_hy(y_pixel,mlx.side, player.angle); 
	end.x =  ft_first_hit_hx(player,player.angle,end.y);

	ya = ft_get_ya(player.angle, mlx.side, 1); 
	xa = ya / tan(ft_degree_to_radian(player.angle));

	while(!ft_is_wall(end.x,end.y,mlx) && ft_on_screen(end,mlx))
	{
		end.x = end.x + xa;
		end.y = end.y + ya;
	}
	return (end);
}

t_point ft_end_hit_v(t_player player, t_mlx mlx, double x_pixel)
{
	t_point end;
	double ya;
	double xa;
	
	end.x = ft_first_hit_vx(x_pixel, mlx.side, player.angle); 
	end.y = ft_first_hit_vy(player,player.angle,end.x);

	xa = ft_get_ya(player.angle, mlx.side, 2); 
	ya = xa / tan(ft_degree_to_radian(player.angle));

	return (end);
	 while(!ft_is_wall(end.x + xa,end.y + ya,mlx) && ft_on_screen(end,mlx))
	{
		end.x = end.x + xa;
		end.y = end.y + ya;
	}

	return (end);
}

