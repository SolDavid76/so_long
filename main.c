/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djanusz <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 15:07:01 by djanusz           #+#    #+#             */
/*   Updated: 2023/01/25 18:42:55 by djanusz          ###   ########.fr       */
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
	res = malloc(sizeof(char *) * i + 1);
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
	print_map(map);
	printf("x : %d\n", ft_strchr(map[ft_mapchr(map, 'P')], 'P'));
	printf("y : %d\n", ft_mapchr(map, 'P'));
	fake = dup_map(map);
	printf("res = %d\n", path_finding_aux(fake, 1, 2));
	print_map(fake);
	free_map(fake);
	if (valid_map_border(map) || valid_map_content(map))
		return (free_map(map), write(1, "ERROR\n", 6), 1);
	else
		return (free_map(map), write(1, "FINE\n", 5), 1);
}

/*
int	main(void)
{
	void	*mlx;
	void	*window;

	mlx = mlx_init();
	window = mlx_new_window(mlx, 400, 400, "Hello world");
	mlx_loop(mlx);
	return (0);
}
*/
