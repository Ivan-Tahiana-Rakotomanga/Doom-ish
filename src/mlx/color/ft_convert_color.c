/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_color.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fxu-lin <fxu-lin@student.42antananarivo.m  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/20 15:51:13 by fxu-lin           #+#    #+#             */
/*   Updated: 2025/06/20 15:51:13 by fxu-lin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/header.h"

int ft_convert_color(char *color)
{
  int res;
  char **colors;
  int first_c;
  int second_c;
  int third_c;

  res = 0;
  colors = ft_split(color, ',');
  if (!colors)
    ft_free_str(colors);
  first_c = ft_atoi(colors[0]);
  second_c = ft_atoi(colors[1]);
  third_c = ft_atoi(colors[2]);
  res = (first_c << 16) | (second_c << 8) | (third_c);
  ft_free_str(colors);
  return (res);
}


