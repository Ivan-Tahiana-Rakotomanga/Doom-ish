/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw_ceiling_floor.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irakotom <irakotom@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/12 09:01:59 by irakotom          #+#    #+#             */
/*   Updated: 2025/08/12 09:02:59 by irakotom         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../../../includes/header.h"

void	ft_draw_ceiling_floor(t_mlx mlx, t_point a, t_point b)
{
	t_point	start;
	t_point	end;

	start.x = a.x;
	start.y = 0;
	end.x = b.x;
	end.y = a.y;
	ft_draw_rect(start, end, mlx.utils.c, &mlx);
	start.x = a.x;
	start.y = b.y;
	end.x = b.x;
	end.y = mlx.height;
	ft_draw_rect(start, end, mlx.utils.f, &mlx);
}
