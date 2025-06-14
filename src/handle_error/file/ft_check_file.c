#include "../../../includes/header.h"

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

int	ft_handle_index_id(char *line)
{
	int		value;
	char	**lines;

	lines = ft_split(line, ' ');
	value = ft_index_id(lines[0]);
	if (value == 0)
		return (0);
	if (value < 5)
	{
		if (ft_many_args_textures(lines)) /*|| !ft_is_valid_path(lines[1], ".xpm"))*/
			return (0);
	}
	else if (value > 4)
	{
		if (ft_many_args_textures(lines))
			return (0);
		if (!ft_check_colors(lines[1]))
			return (0);
	}
	return (value);
}

void	ft_inits_int(int *i, int *j, int *k)
{
	*i = 0;
	*j = 0;
	*k = 0;
}

int	ft_check_all_line(int fd)
{
	char	*line;
	int		value;
	int		temp_value;
	int		id;

	ft_inits_int(&id, &temp_value, &value);
	line = ft_first_line(fd);
	if (!line)
		return (0);
	while (id < 6 && line) { if (!ft_is_empty_str(line))
		{
			temp_value = ft_handle_index_id(line);
			if (temp_value == 0)
				return (0);
			value = value + temp_value;
			id++;
		}
		line = ft_first_line(fd);
	}
	if (value != 21)
	{
		ft_putstr_fd("Error\nDuplicate ID in file or it is missing ID\n", 2);
		return (0);
	}
	return (1);
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
/*int	main(int argc, char **argv)
  { int		fd; char	*line;

	if (argc != 2)
	{
		printf("tsy ampy an'ilay fichier");
		return (0);
	}
	fd = open(argv[1], O_RDONLY);
	while ((line = ft_get_next_line(fd)) != NULL)
	{
		printf("%s\n", line);
		free(line);
	}
	close(fd);
	return (0);
}*/
