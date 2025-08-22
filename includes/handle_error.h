/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_error.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fxu-lin <fxu-lin@student.42antananarivo.m  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/10 09:43:54 by fxu-lin           #+#    #+#             */
/*   Updated: 2025/07/29 10:13:20 by irakotom         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HANDLE_ERROR_H
# define HANDLE_ERROR_H
# include "all_struct.h"

int		ft_is_valid_path(char *path, char *extension);
int		ft_valid_arg_count(int argc);
int		ft_valid_file(char *file);
int		ft_many_args_textures(char **lines);
int		ft_valid_extension(char *file, char *extension);
int		ft_is_duplicate_color(char *floor, char *ceiling);
int		ft_valid_color(int color, char *color_str);
int		ft_format_map_is_valid(char **map);
int		ft_check_colors(char *color);
int		ft_index_id(char *id);
char	*ft_first_line(int fd);
int		ft_handle_index_id(char *line, char **one, char **two);
int		ft_is_orientation(char c);
int		ft_check_under_map(t_map *map);
int		ft_check_file(char *file, char ***map_str, t_utils *utils);
int		ft_map_is_closed(char **map);
void	ft_get_info(char *file, t_utils *utils);
int		ft_check_xpm(char *filename);
int		ft_get_height_map(t_map *map);
int		ft_get_width_map(t_map *map);
int		ft_exposed_file(char *file);
int		ft_over_int_max(const char *str);
int		ft_valid_around(char **map, int x, int y, int *w_h);

#endif
