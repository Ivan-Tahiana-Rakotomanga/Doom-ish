#include "../../../includes/header.h"

void ft_draw_ray(double angle,t_player *player, t_mlx *mlx)
{
	t_point a;
	t_point end;

	a.x = player->x;
	a.y = player->y;


     // end.y =  ft_first_hit_hy(a.y,mlx->side, angle); 
	 // end.x =  ft_first_hit_hx(*player,angle,end.y);
	(void)angle;

	// end = ft_end_hit_h(*player,*mlx,a.y);
	end = ft_end_hit_v(*player,*mlx,a.x);

	


	// printf("Ito ilay %f  ito ilay xdepart %f ydepart %f  xarriver %f yarriver %f \n", angle,a.x,a.y,end.x,end.y);
	ft_draw_line(a,end,ft_strdup("0,0,255"),mlx);

	/*
   	// ft_draw_line(a,end,ft_strdup("0,255,0"),mlx);

	end.x = ft_first_hit_vx(a.x,mlx->side,angle);
	end.y = ft_first_hit_vy(*player,angle,end.x);
	if (mlx->height <= end.y  )
		end.y = mlx->height; 
	if (end.y < 0)
		end.y = 0;

	end.x = a.x + cos(ft_degree_to_radian(angle)) * 10;
	end.y = a.y + sin(ft_degree_to_radian(angle)) * 10;


	ft_draw_line(a,end,ft_strdup("255,0,0"),mlx);
	*/
}

void ft_draw_all_rays(t_player *player, t_mlx *mlx)
{
	/*double angle_step;
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
	}*/

	ft_draw_ray(player->angle, player, mlx);
}
