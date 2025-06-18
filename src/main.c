/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irakotom <irakotom@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/04 13:05:56 by irakotom          #+#    #+#             */
/*   Updated: 2025/06/11 13:26:00 by irakotom         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/header.h"


/*void	ft_print_strs(char **strs)
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
}*/

int	main(int argc, char **argv)
{
	char	**map;

	if (argc == 2)
	{
		map = NULL;
		if (!ft_check_file(argv[1], &map))
			return (0);
		/*ft_print_strs(map);*/
		ft_free_str(map);
	}
	return (0);
}
