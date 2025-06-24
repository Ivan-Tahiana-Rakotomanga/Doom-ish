/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   all_struct.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fxu-lin <fxu-lin@student.42antananarivo.m  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 13:16:38 by fxu-lin           #+#    #+#             */
/*   Updated: 2025/06/18 16:40:19 by fxu-lin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ALL_STRUCT_H
# define ALL_STRUCT_H

typedef struct s_map
{
	char			*line;
	struct s_map	*next;
}					t_map;

typedef struct s_mlx
{
	void			*mlx;
	void			*win;
	void			*img;
	void			*adr;
	int				width;
	int				color;
	int				height;
	int				bpp;
	int				s_line;
	int				endian;
	int				x_player;
	int				y_player;
	char			**map;
	double			change_x;
	double			change_y;
}					t_mlx;

typedef struct s_point
{
	double			x;
	double			y;

}					t_point;

#endif
