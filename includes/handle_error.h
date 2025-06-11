/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_error.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fxu-lin <fxu-lin@student.42antananarivo.m  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/10 09:43:54 by fxu-lin           #+#    #+#             */
/*   Updated: 2025/06/11 14:15:34 by irakotom         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HANDLE_ERROR_H
# define HANDLE_ERROR_H

int	ft_valid_arg_count(int argc);
int	ft_valid_file(char *file);
int	ft_valid_extension(char *file, char *extension);
int	ft_is_duplicate_color(char *floor, char *ceiling);
int	ft_valid_color(int color);
int	ft_format_map_is_valid(char **map);
int ft_check_colors(char *color);
int ft_index_id(char *id);
#endif
