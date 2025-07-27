#include "../../../includes/header.h"

t_img	ft_get_texture(t_mlx mlx, int index)
{
	if (index == 1)
		return (mlx.no);
	else if (index == 2)
		return (mlx.so);
	else if (index == 3)
		return (mlx.ea);
	else
		return (mlx.wo);
}

unsigned int	*ft_get_address_textures(int y, int h, t_mlx *mlx,
		double *dst_orient)
{
	char	*address;
	int		x;
	t_img	img;

	img = ft_get_texture(*mlx, (int)dst_orient[0]);
	x = ft_rules_of_three(dst_orient[1], mlx->side, img.width);
	y = ft_get_new_y(y, h, img.height);
	address = img.adr + (y * img.s_line + x * (img.bpp / 8));
	return ((unsigned int *)address);
}

void	ft_draw_rect_textures(t_point a, t_point b, t_mlx *mlx, double *dst_o)
{
	char	*tmp_color;
	double	h;
	double	tmp_x;
	double	s;

	s = 0.0;
	h = b.y - a.y;
	tmp_x = a.x;
	tmp_color = NULL;
	while (a.y < b.y)
	{
		a.x = tmp_x;
		while (a.x < b.x)
		{
			tmp_color = ft_get_address(a.x, a.y, mlx);
			*(unsigned int *)tmp_color = *ft_get_address_textures(s, h, mlx,
					dst_o);
			a.x++;
		}
		s++;
		a.y++;
	}
}
