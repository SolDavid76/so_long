/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djanusz <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 15:07:01 by djanusz           #+#    #+#             */
/*   Updated: 2023/02/08 16:55:27 by djanusz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/*static t_win	ft_game_init(char *map_path)
{
	char	**map;
	t_win	win;

	map = parsing(map_path);
	if (!map)
		exit(0);
	win.map.str = map;
	win = create_window(win.map.str);
	win.map.wall = ft_image_from_xpm(win, "textures/bush.xpm", 50, 50);
	win.map.player = ft_image_from_xpm(win, "textures/player.xpm", 50, 50);
	win.map.grass = ft_image_from_xpm(win, "textures/grass.xpm", 50, 50);
	win.map.item = ft_image_from_xpm(win, "textures/pokeball.xpm", 50, 50);
	win.map.exit = ft_image_from_xpm(win, "textures/exit.xpm", 50, 50);
	win.map.x_exit = ft_strchr(map[ft_mapchr(map, 'E')], 'E');
	win.map.y_exit = ft_mapchr(map, 'E');
	rendering(win, win.map.str);
	return (win);
}*/

void	ft_exit(t_win win)
{
	free_map(win.map.str);
	mlx_destroy_window(win.mlx, win.ptr);
	mlx_destroy_image(win.mlx, win.frame.ptr);
	mlx_destroy_image(win.mlx, win.map.grass.ptr);
	mlx_destroy_image(win.mlx, win.map.wall.ptr);
	mlx_destroy_image(win.mlx, win.map.item.ptr);
	mlx_destroy_image(win.mlx, win.map.exit.ptr);
	mlx_destroy_image(win.mlx, win.map.player.ptr);
	mlx_destroy_display(win.mlx);
	free(win.mlx);
	exit(0);
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
	win.map.wall = ft_image_from_xpm(win, "textures/bush.xpm", 50, 50);
	win.map.player = ft_image_from_xpm(win, "textures/player.xpm", 50, 50);
	win.map.grass = ft_image_from_xpm(win, "textures/grass.xpm", 50, 50);
	win.map.item = ft_image_from_xpm(win, "textures/pokeball.xpm", 50, 50);
	win.map.exit = ft_image_from_xpm(win, "textures/exit.xpm", 50, 50);
	win.map.x_exit = ft_strchr(map[ft_mapchr(map, 'E')], 'E');
	win.map.y_exit = ft_mapchr(map, 'E');
	rendering(win, win.map.str);
	mlx_key_hook(win.ptr, &handle_input, &win);
	mlx_loop(win.mlx);
}
