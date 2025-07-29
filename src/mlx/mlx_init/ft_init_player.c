#include "../../../includes/header.h"

double	ft_pixel_player(int value, t_mlx *mlx)
{
	double	half;

	half = ((double)mlx->side / 2);
	return (ft_coordinate_to_pixel((double)value, mlx->side) + half);
}

int	ft_init_player(t_mlx **mlx, double angle)
{
	t_player	*player;

	player = malloc(sizeof(t_player));
	if (!player)
		return (0);
	ft_memset(player, 0, sizeof(t_player));
	player->x = ft_pixel_player((*mlx)->x_player, *mlx);
	player->y = ft_pixel_player((*mlx)->y_player, *mlx);
	player->fov = 60;
	player->nb_rays = (*mlx)->width / (*mlx)->width_one_wall;
	player->speed = 10;
	player->angle_speed = 2;
	player->angle = angle;
	(*mlx)->player = player;
	return (1);
}
