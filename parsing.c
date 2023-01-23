/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djanusz <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 13:21:20 by djanusz           #+#    #+#             */
/*   Updated: 2023/01/23 17:21:06 by djanusz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	**create_map(int fd)
{
	char	**res;
	t_list	**tmp;
	t_list	*lst;
	int		i;
	int		x;

	x = 1;
	lst = ft_lstnew(get_next_line(fd));
	tmp = &lst;
	while (x)
	{
		ft_lstadd_back(tmp, ft_lstnew(get_next_line(fd)));
		if ((ft_lstlast(lst))->content == NULL)
			x = 0;
	}
	res = malloc(sizeof(char *) * ft_lstsize(lst));
	if (!res)
		return (NULL);
	i = 0;
	while (lst)
	{
		res[i] = lst->content;
		lst = lst->next;
		i++;
	}
	return (res);
}

static int	valid_map_content(char **map)
{
	int	i;
	int	j;
	int	data[3];

	data[0] = 0;
	data[1] = 0;
	data[2] = 0;
	i = -1;
	while (map[++i])
	{
		j = -1;
		while (map[i][++j])
		{
			if (map[i][j] == 'P')
				data[0]++;
			else if (map[i][j] == 'E')
				data[1]++;
			else if (map[i][j] == 'C')
				data[2]++;
			else if (map[i][j] != '0' && map[i][j] != '1' && map[i][j] != '\n')
				return (1);
		}
	}
	return (data[0] != 1 || data[1] != 1 || data[2] == 0);
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
		i++;
	}
}

int	main(void)
{
	int		fd;
	char	**map;

	fd = open("map.ber", O_RDONLY);
	map = create_map(fd);
	print_map(map);
	if (valid_map_content(map))
		return (write(1, "ERROR\n", 6), 1);
	else
		return (write(1, "FINE\n", 5), 1);
}
