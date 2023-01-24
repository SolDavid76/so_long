/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djanusz <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 13:21:20 by djanusz           #+#    #+#             */
/*   Updated: 2023/01/24 15:21:05 by djanusz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static char	**create_map(int fd)
{
	char	**res;
	t_list	*lst;
	t_list	*tmp;
	int		i;

	lst = ft_lstnew(get_next_line(fd));
	while ((ft_lstlast(lst)->content) != NULL)
		ft_lstadd_back(&lst, ft_lstnew(get_next_line(fd)));
	res = malloc(sizeof(char *) * ft_lstsize(lst));
	if (!res)
		return (NULL);
	i = 0;
	while (lst)
	{
		tmp = lst->next;
		res[i++] = lst->content;
		free(lst);
		lst = tmp;
	}
	return (res);
}

static int	valid_map_border(char **map)
{
	int	len;
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (map[i][j])
	{
		if (map[i][j] != '1')
			return (1);
		j++;
	}
	len = ft_strlen(map[0]);
	while (map[i + 1])
	{
		if (ft_strlen(map[i]) != len
			|| map[i][0] != '1' || map[i][len - 1] != '1')
			return (1);
		i++;
	}
	j = 0;
	while (map[i][j])
	{
		if (ft_strlen(map[i]) != len || map[i][j] != '1')
			return (1);
		j++;
	}
	return (0);
}

static int	valid_map_content(char **map)
{
	int	i;
	int	j;
	int	data[3];

	data[SPAWN] = 0;
	data[EXIT] = 0;
	data[ITEM] = 0;
	i = -1;
	while (map[++i])
	{
		j = -1;
		while (map[i][++j])
		{
			if (map[i][j] == 'P')
				data[SPAWN]++;
			else if (map[i][j] == 'E')
				data[EXIT]++;
			else if (map[i][j] == 'C')
				data[ITEM]++;
			else if (map[i][j] != '0' && map[i][j] != '1' && map[i][j] != '\n')
				return (1);
		}
	}
	return (data[SPAWN] != 1 || data[EXIT] != 1 || data[ITEM] == 0);
}

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

	fd = open("map.ber", O_RDONLY);
	map = create_map(fd);
	print_map(map);
	if (valid_map_border(map) || valid_map_content(map))
		return (free_map(map), write(1, "ERROR\n", 6), 1);
	else
		return (free_map(map), write(1, "FINE\n", 5), 1);
}
