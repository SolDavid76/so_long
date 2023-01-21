/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djanusz <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 13:21:20 by djanusz           #+#    #+#             */
/*   Updated: 2023/01/21 13:53:12 by djanusz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	valid_map(char **map)
{
	
}

static int	valid_map_content(char **map)
{
	int	i;
	int	j;
	int	start;
	int	exit;
	int	item;

	i = -1;
	start = 0;
	exit = 0;
	item = 0;
	while (map[++i])
	{
		j = -1;
		while (map[i][++j])
		{
			if (map[i][j] == 'P')
				start++;
			if (map[i][j] == 'E')
				exit++;
			if (map[i][j] == 'C')
				item++;
		}
	}
	return (start != 1 || exit != 1 || item == 0);
}

int	parsing(char **map)
{
}
