/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djanusz <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 09:44:28 by djanusz           #+#    #+#             */
/*   Updated: 2023/02/07 18:33:36 by djanusz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	handle_input(int key, t_win *win)
{
	if (key == 65307)
		exit(0);
	if (key == 97 || key == 100 || key == 115 || key == 119)
		move(*win, win->map.str, key);
	return (0);
}

int	move(t_win win, char **map, int key)
{
	int	x;
	int	y;

	x = ft_strchr(map[ft_mapchr(map, 'P')], 'P');
	y = ft_mapchr(map, 'P');
	if (key == 97 && map[y][x - 1] != '1')
		map[y][x - 1] = 'P';
	else if (key == 100 && map[y][x + 1] != '1')
		map[y][x + 1] = 'P';
	else if (key == 115 && map[y + 1][x] != '1')
		map[y + 1][x] = 'P';
	else if (key == 119 && map[y - 1][x] != '1')
		map[y - 1][x] = 'P';
	else
		return (0);
//	if (ft_mapchr(win.map.str, 'E')) <--- this is dog shit.
	map[y][x] = '0';
//	else
//		map[y][x] = 'E';
	rendering(win, win.map.str);
	return (1);
}
