/* ************************************************************************** */
/*                                                                           */
/*                                                        :::      ::::::::   */
/*   ft_check_file.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fxu-lin <fxu-lin@student.42antananarivo.m  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 08:26:46 by fxu-lin           #+#    #+#             */
/*   Updated: 2025/06/17 16:31:26 by irakotom         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/header.h"

int	ft_loop_check_line(char **line, int fd, char **one, char **two)
{
	int	value;
	int	id;
	int	temp_value;

	id = 0;
	value = 0;
	temp_value = 0;
	while (id < 6 && *line)
	{
		if (!ft_is_empty_str(*line))
		{
			temp_value = ft_handle_index_id(*line, one, two);
			if (temp_value == 0)
				return (0);
			value = value + temp_value;
			id++;
		}
		free(*line);
		*line = ft_get_next_line(fd);
	}
	return (value);
}

int	ft_check_all_line(int fd)
{
	char	*line;
	char	*one;
	char	*two;
	int		value;

	one = NULL;
	two = NULL;
	value = 0;
	line = ft_first_line(fd);
	if (line == NULL)
		return (0);
	value = ft_loop_check_line(&line, fd, &one, &two);
	free(line);
	if (value == 0)
		return (free(one), free(two), 0);
	if (value != 21)
	{
		ft_putstr_fd("Error\nDuplicate ID in file or it is missing ID\n", 2);
		return (free(one), free(two), 0);
	}
	if (ft_is_duplicate_color(one, two))
		return (free(one), free(two), 0);
	return (free(one), free(two), 1);
}

int	ft_check_file(char *file, char ***map_str)
{
	int		fd;
	t_map	*map;

	fd = 0;
	map = NULL;
	if (!ft_is_valid_path(file, ".cub"))
		return (0);
	fd = open(file, O_RDONLY);
	if (ft_error_fd(fd))
		return (0);
	if (!ft_check_all_line(fd))
		return (0);
	if (!ft_fill_map(&map, fd))
		return (0);
	if (!ft_check_under_map(map))
	{
		ft_free_map(&map);
		return (0);
	}
	*map_str = ft_map_to_strs(map);
	ft_free_map(&map);
	close(fd);
	return (1);
}

void	ft_print_strs(char **strs)
{
	int	i;

	i = 0;
	printf("\nIto ny print an'ilay strs\n");
	while (strs[i])
	{
		printf("%s\n", strs[i]);
		i++;
	}
	printf("\n");
}

void	ft_print_map(t_map *map)
{
	printf("\nIto ny print an'ilay map\n");
	while (map)
	{
		printf("%s\n", map->line);
		map = map->next;
	}
	printf("\n");
}

int	main(int argc, char **argv)
{
	char	**map;

	if (argc == 2)
	{
		map = NULL;
		if (!ft_check_file(argv[1], &map))
			return (0);
		ft_print_strs(map);
		ft_free_str(map);
	}
	return (0);
}

/*int	main(int argc, char **argv)
{
	if (argc == 2)
		printf("Ito %d\n", ft_check_file(argv[1]));
	return (0);
}*/
