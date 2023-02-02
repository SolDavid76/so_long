/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djanusz <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 13:21:20 by djanusz           #+#    #+#             */
/*   Updated: 2023/02/01 15:16:15 by djanusz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	**create_map(int fd)
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

int	valid_map_border(char **map)
{
	int	len;
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (map[i][j])
	{
		if (map[i][j++] != '1')
			return (1);
	}
	len = ft_strlen(map[0]);
	while (map[i + 1])
	{
		if (ft_strlen(map[i]) != len
			|| map[i][0] != '1' || map[i++][len - 1] != '1')
			return (1);
	}
	j = 0;
	while (map[i][j])
	{
		if (ft_strlen(map[i]) != len || map[i][j++] != '1')
			return (1);
	}
	return (0);
}

int	valid_map_content(char **map)
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

char	**parsing(void)
{
	int		fd;
	char	**map;
	char	**fake;

	fd = open("map.ber", O_RDONLY);
	if (fd < 0)
		return (write(1, "FILE NOT FOUND !\n", 17), NULL);
	map = create_map(fd);
	fake = dup_map(map);
	if (valid_map_border(fake))
	{
		free_map(map);
		return (free_map(fake), write(1, "INVALID MAP BORDER !\n", 21), NULL);
	}
	if (valid_map_content(fake))
	{
		free_map(map);
		return (free_map(fake), write(1, "INVALID MAP CONTENT !\n", 22), NULL);
	}
	if (path_finding(fake))
	{
		free_map(map);
		return (free_map(fake), write(1, "INVALID PATH !\n", 15), NULL);
	}
	return (free_map(fake), map);
}
