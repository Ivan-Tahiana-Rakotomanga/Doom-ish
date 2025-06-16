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
