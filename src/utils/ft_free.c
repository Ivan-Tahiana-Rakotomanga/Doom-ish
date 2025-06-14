#include "../../includes/header.h"

void	ft_free_str(char **str)
{
	int	i;

	i = 0;
	if (!str[i] || !str)
		return ;
	while (str[i])
	{
		free(str[i]);
		str[i] = NULL;
		i++;
	}
	free(str);
	str = NULL;
}
