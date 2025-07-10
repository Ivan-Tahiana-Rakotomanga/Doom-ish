#include "../../../includes/header.h"

void ft_draw_ray(double angle,t_player *player, t_mlx *mlx)
{
	int x_cos;
	int y_sin;
	t_point a;
	t_point end;

	a.x = player->x;
	a.y = player->y;
    x_cos = cos(ft_degree_to_radian(angle))  * 50;
	y_sin = sin(ft_degree_to_radian(angle))  * 50;
	end.x =  a.x + x_cos ;
	end.y =  a.y + y_sin ; 
	ft_draw_line(a,end,ft_strdup("0,0,255"),mlx);
}

void ft_draw_all_rays(t_player *player, t_mlx *mlx)
{
	double angle_step;
	double start_angle;
	int nbr_rays;
	int i;

	i = 0;
	nbr_rays = player->nb_rays;
	angle_step = player->fov / nbr_rays;
	start_angle = player->angle - (player->fov / 2);
	while(i < nbr_rays)
	{
		ft_draw_ray(start_angle,player, mlx);

		start_angle = start_angle + angle_step;
		i++;
	}

}
