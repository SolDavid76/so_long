/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djanusz <djanusz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 15:07:01 by djanusz           #+#    #+#             */
/*   Updated: 2023/02/10 11:48:36 by djanusz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_exit(t_win *win)
{
	free_map(win->map.str);
	mlx_destroy_window(win->mlx, win->ptr);
	mlx_destroy_image(win->mlx, win->frame.ptr);
	mlx_destroy_image(win->mlx, win->map.grass.ptr);
	mlx_destroy_image(win->mlx, win->map.wall.ptr);
	mlx_destroy_image(win->mlx, win->map.item.ptr);
	mlx_destroy_image(win->mlx, win->map.exit.ptr);
	mlx_destroy_image(win->mlx, win->map.player.ptr);
	mlx_destroy_display(win->mlx);
	free(win->mlx);
	exit(0);
	return (0);
}

int	main(int ac, char **av)
{
	char	**map;
	t_win	win;

	if (ac == 1)
		map = parsing("map.ber");
	else if (ac == 2)
		map = parsing(av[1]);
	else
		return (write(1, "Invalid args for map path !\n", 28), 1);
	if (!map)
		return (1);
	win = create_window(map);
	win.map.str = map;
	win.map.wall = ft_image_from_xpm(win, "textures/tree.xpm", 50, 50);
	win.map.player = ft_image_from_xpm(win, "textures/player.xpm", 50, 50);
	win.map.grass = ft_image_from_xpm(win, "textures/grass.xpm", 50, 50);
	win.map.item = ft_image_from_xpm(win, "textures/pokeball.xpm", 50, 50);
	win.map.exit = ft_image_from_xpm(win, "textures/exit.xpm", 50, 50);
	win.map.x_exit = ft_strchr(map[ft_mapchr(map, 'E')], 'E');
	win.map.y_exit = ft_mapchr(map, 'E');
	rendering(win, win.map.str);
	mlx_hook(win.ptr, KeyPress, KeyPressMask, &handle_input, &win);
	mlx_hook(win.ptr, 17, 0, &ft_exit, &win);
	mlx_loop(win.mlx);
}
