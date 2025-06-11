/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fxu-lin <fxu-lin@student.42antananari      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 11:36:48 by fxu-lin           #+#    #+#             */
/*   Updated: 2024/11/20 14:19:32 by fxu-lin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_count_words(const char *s, char c)
{
	size_t	count;

	count = 0;
	while (*s)
	{
		while (*s && *s == c)
			s++;
		if (*s)
			count++;
		while (*s && *s != c)
			s++;
	}
	return (count);
}

char	*ft_allocate_words(const char *s, char c)
{
	const char	*start;

	start = s;
	while (*s && *s != c)
		s++;
	return (ft_substr(start, 0, s - start));
}

void	ft_free_resutlt(char **result, size_t words)
{
	while (words--)
		free(result[words]);
	free(result);
}

void	ft_split_string(char **result, const char *s, char c)
{
	size_t	words;
	size_t	i;

	words = 0;
	i = 0;
	while (*s)
	{
		while (*s && *s == c)
			s++;
		if (*s)
		{
			result[i++] = ft_allocate_words(s, c);
			if (!result[i - 1])
			{
				ft_free_resutlt(result, i - 1);
				return ;
			}
			words++;
			while (*s && *s != c)
				s++;
		}
	}
	result[words] = NULL;
}

char	**ft_split(const char *s, char c)
{
	char	**result;
	size_t	words;

	if (!s)
		return (NULL);
	words = ft_count_words(s, c);
	result = (char **)malloc(sizeof(char *) * (words + 1));
	if (!result)
	{
		free(result);
		return (NULL);
	}
	ft_split_string(result, s, c);
	return (result);
}
