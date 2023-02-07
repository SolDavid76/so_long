/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djanusz <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 15:07:01 by djanusz           #+#    #+#             */
/*   Updated: 2023/02/07 18:20:11 by djanusz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(void)
{
	char	**map;
	t_win	win;

	map = parsing();
	if (!map)
		return (1);
	win = create_window(map);
	win.map.str = map;
	win.map.wall = ft_image_from_xpm(win, "textures/bush.xpm", 50, 50);
	win.map.player = ft_image_from_xpm(win, "textures/player.xpm", 50, 50);
	win.map.grass = ft_image_from_xpm(win, "textures/grass.xpm", 50, 50);
	win.map.item = ft_image_from_xpm(win, "textures/pokeball.xpm", 50, 50);
	win.map.exit = ft_image_from_xpm(win, "textures/exites.xpm", 50, 50);
	win.map.x_exit = ft_strchr(map[ft_mapchr(map, 'E')], 'E');
	win.map.y_exit = ft_mapchr(map, 'E');
	rendering(win, win.map.str);
	mlx_key_hook(win.ptr, &handle_input, &win);
	mlx_loop(win.mlx);
}
