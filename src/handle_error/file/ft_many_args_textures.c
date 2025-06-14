#include "../../../includes/header.h"

int	ft_many_args_textures(char **lines)
{
	if (ft_strs_len(lines) != 2)
	{
		ft_putstr_fd("Error\n Many arguments at the texture level\n", 2);
		return (1);
	}
	return (0);
}
