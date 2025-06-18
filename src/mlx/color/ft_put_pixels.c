#include "../../../includes/header.h"

void	ft_draw_pixel(int i, int j, t_mlx *mlx, int *xy)
{
	int	pixel_x;
	int	pixel_y;
	int	index;

	index = 0;
	pixel_x = (j) * ft_get_limit_x(mlx) + xy[0];
	pixel_y = (i) * ft_get_limit_y(mlx) + xy[1];
	index = (pixel_y * mlx->s_line) + (pixel_x * (mlx->bpp) / 8);
	if (pixel_x < mlx->width && pixel_y < mlx->height)
		*(int *)(mlx->adr + index) = mlx->color;
}

void	ft_put_pixels(t_mlx *mlx, int i, int j)
{
	int	xy[2];
	int	limit_x;
	int	limit_y;

	ft_get_limits_size(&limit_x, &limit_y, mlx);
	xy[0] = 0;
	xy[1] = 0;
	while (xy[1] < limit_y)
	{
		xy[0] = 0;
		while (xy[0] < limit_x)
		{
			ft_draw_pixel(i, j, mlx, xy);
			xy[0]++;
		}
		xy[1]++;
	}
}
