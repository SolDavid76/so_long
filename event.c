/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djanusz <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 09:44:28 by djanusz           #+#    #+#             */
/*   Updated: 2023/02/08 11:47:08 by djanusz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	ft_putchar(char c)
{
	return (write(1, &c, 1));
}

static int	ft_putnbr(unsigned int nb)
{
	int	digit;
	int	res;

	res = 0;
	if (nb < 10)
		res += ft_putchar(nb + 48);
	else
	{
		digit = nb % 10;
		nb /= 10;
		res += ft_putnbr(nb);
		res += ft_putchar(digit + 48);
	}
	return (res);
}

int	handle_input(int key, t_win *win)
{
	static unsigned int	i = 1;

	if (key == 65307)
		ft_exit(*win);
	if (key == 97 || key == 100 || key == 115 || key == 119)
	{
		if (move(*win, win->map.str, key))
		{
			ft_putnbr(i++);
			write(1, "\n", 1);
		}
	}
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
	map[y][x] = '0';
	if (map[win.map.y_exit][win.map.x_exit] == '0')
		map[y][x] = 'E';
	if (!ft_mapchr(map, 'C') && !ft_mapchr(map, 'E'))
		ft_exit(win);
	rendering(win, win.map.str);
	return (1);
}
