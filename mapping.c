/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapping.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djanusz <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 15:07:05 by djanusz           #+#    #+#             */
/*   Updated: 2023/02/01 15:07:55 by djanusz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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

int	ft_maplen(char **map)
{
	int	i;

	i = 0;
	while (map[i])
		i++;
	return (i);
}
