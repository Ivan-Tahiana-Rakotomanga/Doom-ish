/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irakotom <irakotom@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 09:42:32 by irakotom          #+#    #+#             */
/*   Updated: 2025/06/17 15:41:54 by irakotom         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_H
# define MAP_H

t_map	*ft_new_map(char *line);
t_map	*ft_last_map(t_map *map);
void	ft_map_add_back(t_map **map, t_map *new_end_map);
void	ft_free_map(t_map **map);
int		ft_get_height_map(t_map *map);
int		ft_get_width_map(t_map *map);
int		ft_characters_valid_map(char *line);
int		ft_character_valid(char c);
int		ft_fill_map(t_map **map, int fd);
char	**ft_map_to_strs(t_map *map);
int		ft_flood_fill(int x, int y, char **map, int height);
char ft_find_start(int *start_x, int *start_y, char **map);

#endif
