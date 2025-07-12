#include "../../../includes/header.h"

void ft_draw_ray(double angle,t_player *player, t_mlx *mlx)
{
	t_point a;
	t_point end;

	a.x = player->x;
	a.y = player->y;

	end = ft_get_end(angle,*mlx,a.y,a.x);
	ft_draw_line(a,end,ft_strdup("255,0,255"),mlx);

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
	start_angle = ft_limit_angle(fmod(player->angle - (player->fov / 2),360));
	while(i < nbr_rays)
	{
		ft_draw_ray(start_angle,player, mlx);
		start_angle = ft_limit_angle(fmod((start_angle + angle_step),360));
		i++;
	}
}
