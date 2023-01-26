/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djanusz <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 15:07:01 by djanusz           #+#    #+#             */
/*   Updated: 2023/01/26 15:09:45 by djanusz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	print_map(char **map)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			write(1, &map[i][j], 1);
			j++;
		}
		write(1, "\n", 1);
		i++;
	}
}

char	**dup_map(char **map)
{
	char	**res;
	int		i;
	int		j;

	i = 0;
	while (map[i])
		i++;
	res = malloc(sizeof(char *) * (i + 1));
	if (!res)
		return (NULL);
	i = 0;
	while (map[i])
	{
		j = 0;
		res[i] = malloc(sizeof(char) * ft_strlen(map[i]) + 1);
		while (map[i][j])
		{
			res[i][j] = map[i][j];
			j++;
		}
		res[i][j] = '\0';
		i++;
	}
	res[i] = NULL;
	return (res);
}

void	free_map(char **map)
{
	int	i;

	i = 0;
	while (map[i])
	{
		free(map[i]);
		i++;
	}
	free(map);
}

int	main(void)
{
	int		fd;
	char	**map;
	char	**fake;

	fd = open("map.ber", O_RDONLY);
	map = create_map(fd);
	fake = dup_map(map);
	if (valid_map_border(map) || valid_map_content(map) || path_finding(fake))
		return (free_map(map), free_map(fake), write(1, "ERROR\n", 6), 1);
	return (free_map(map), free_map(fake),write(1, "FINE\n", 5), 1);
}
