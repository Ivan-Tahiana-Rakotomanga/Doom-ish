#include "../../../includes/header.h"
#include <stdio.h>

char	*ft_first_line(int fd)
{
	char	*line;

	line = ft_get_next_line(fd);
	if (!line)
	{
		ft_putstr_fd("Error\n This file is empty\n", 2);
		return (NULL);
	}
	return (line);
}

int	ft_handle_index_id(char *line, char **one, char **two)
{
	int		value;
	char	**lines;
	char	*temp_lines;

	lines = ft_split(line, ' ');
	value = ft_index_id(lines[0]);
	temp_lines = NULL;
	if (value == 0)
  {
    ft_free_str(lines);
		return (0);
  }
	temp_lines = ft_strtrim(lines[1], " \n");
	if (value < 5)
	{
		if (!ft_valid_file(temp_lines))
      return (free(temp_lines), ft_free_str(lines), 0);
    free(temp_lines);
	}
	else if (value > 4)
	{
    free(temp_lines);
    temp_lines = line;
    temp_lines++;
    
		if (!ft_check_colors(temp_lines))
      return (ft_free_str(lines), 0);
		if (!*one)
			*one = ft_strdup(temp_lines);
		else if (!*two)
			*two = ft_strdup(temp_lines);
	}
	return (ft_free_str(lines), value);
}

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

int	ft_check_file(char *file)
{
	int	fd;
	int	res;

	fd = 0;
	res = 0;
	if (!ft_is_valid_path(file, ".cub"))
		return (0);
	fd = open(file, O_RDONLY);
	if (ft_error_fd(fd))
		return (0);
	res = ft_check_all_line(fd);
	close(fd);
	return (res);
}
int	main(int argc, char **argv)
{
	if (argc == 2)
		printf("Ito %d\n", ft_check_file(argv[1]));
	return (0);
}
