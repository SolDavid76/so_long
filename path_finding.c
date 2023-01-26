/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_finding.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djanusz <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 14:35:48 by djanusz           #+#    #+#             */
/*   Updated: 2023/01/26 14:11:10 by djanusz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_strchr(char *str, char c)
{
	int	i;

	if (!str)
		return (0);
	i = 0;
	while (str[i])
	{
		if (str[i] == c)
			return (i);
		i++;
	}
	return (0);
}

static int	ft_mapchr(char **map, char c)
{
	int	i;

	i = 0;
	while (map[i])
	{
		if (ft_strchr(map[i], c))
			return (i);
		i++;
	}
	return (0);
}

static int	path_finding_aux(char **map, int x, int y)
{
	int	res;
	int	i;

	i = 1;
	res = 0;
	while (map[y][x + i] && map[y][x + i] != '1' && map[y][x + i] != 'X')
		map[y][x + i++] = 'X';
	res += i - 1;
	i = 1;
	while (map[y][x - i] && map[y][x - i] != '1' && map[y][x - i] != 'X')
		map[y][x - i++] = 'X';
	res += i - 1;
	i = 1;
	while (map[y + i][x] && map[y + i][x] != '1' && map[y + i][x] != 'X')
		map[y + i++][x] = 'X';
	res += i - 1;
	i = 1;
	while (map[y - i][x] && map[y - i][x] != '1' && map[y - i][x] != 'X')
		map[y - i++][x] = 'X';
	res += i - 1;
	return (res);
}

int	path_finding(char **map)
{
	int	modif;
	int	i;
	int	j;

	modif = 1;
	map[ft_mapchr(map, 'P')][ft_strchr(map[ft_mapchr(map, 'P')], 'P')] = 'X';
	while (modif)
	{
		modif = 0;
		i = 0;
		while (map[i])
		{
			j = 0;
			while (map[i][j] && ft_strchr(map[i], 'X'))
			{
				if (map[i][j] == 'X')
					modif += path_finding_aux(map, j, i);
				j++;
			}
			i++;
		}
		if (modif == 0)
			return (ft_mapchr(map, 'E') || ft_mapchr(map, 'C'));
	}
	return (0);
}
