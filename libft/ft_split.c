/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irakotom <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 08:01:17 by irakotom          #+#    #+#             */
/*   Updated: 2024/03/06 17:27:21 by irakotom         ###   ########.fr       */
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

char	*ft_allocate_word(const char *s, char c)
{
	const char	*start;	

	start = s;
	while (*s && *s != c)
		s++;
	return (ft_substr(start, 0, s - start));
}

void	ft_free_results(char **result, size_t words)
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
			result[i++] = ft_allocate_word(s, c);
			if (!result[i - 1])
			{
				ft_free_results(result, i - 1);
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
		return (NULL);
	ft_split_string(result, s, c);
	return (result);
}
