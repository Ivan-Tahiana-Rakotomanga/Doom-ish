/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irakotom <irakotom@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/11 12:35:07 by irakotom          #+#    #+#             */
/*   Updated: 2025/06/11 13:17:49 by irakotom         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

char	*ft_get_next_line(int fd);
int		ft_strcmp(char const *s1, char const *s2);
int		ft_is_space(char c);
int		ft_is_empty_str(char *str);
int		ft_strs_len(char **strs);
int		ft_is_valid_number(char *nbr);
int		ft_error_fd(int fd);
void	ft_free_str(char **str);

#endif
