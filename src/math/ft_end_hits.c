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
			return (-side);
	  else
	       return (side);
	}
}


int ft_on_screen(double x,double y,t_mlx mlx)
{
	if(x < 0 || mlx.width <= x)
		return (0);
	if(y < 0 || mlx.height <= y)
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

	while(!ft_is_wall(end.x,end.y,mlx))
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

	if(mlx.height < end.y)
	{
		end.y = mlx.height;
		return (end);
	}
	else if ( end.y < 0)
	{
		end.y = 0;
		return (end);
	}

	xa = ft_get_ya(player.angle, mlx.side, 2); 
	ya = xa * tan(ft_degree_to_radian(player.angle));


    while(ft_on_screen(end.x + xa, end.y + ya, mlx) && !ft_is_wall(end.x, end.y, mlx)) 
	{
		end.x = end.x + xa;
		end.y = end.y + ya;
	}
	if(!ft_is_wall(end.x,end.y,mlx))
	{
		if(end.y + ya <= 0)
			end.y = 0;
		else if ( mlx.height <= end.y + ya)
			end.y = mlx.height;

	}
	return (end);
}

double ft_get_distance(t_point end, t_player player)
{
	double x;
	double y;

	x = end.x - player.x; 
	x = x * x;
    y = end.y - player.y; 
	y = y * y;

	return (sqrt(x) + sqrt(y));

}


t_point ft_get_end(t_player player, t_mlx mlx, double y_pixel, double x_pixel)
{
	t_point v;
	t_point h;
	double d_h;
	double d_v;



	h = ft_end_hit_h(player,mlx,y_pixel); 
	v = ft_end_hit_v(player,mlx,x_pixel); 
	d_h = ft_get_distance(h, player);
	d_v = ft_get_distance(v, player);

	if(d_h < d_v)
		return (h);
	else 
		return (v);
}



