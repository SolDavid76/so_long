/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djanusz <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 15:07:01 by djanusz           #+#    #+#             */
/*   Updated: 2023/02/06 14:19:12 by djanusz          ###   ########.fr       */
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
	win.wall = ft_image_from_xpm(win, "textures/bush.xpm", 50, 50);
	win.player = ft_image_from_xpm(win, "textures/player.xpm", 50, 50);
	rendering(win, map);
	mlx_put_image_to_window(win.mlx, win.ptr, win.frame.ptr, 0, 0);
	mlx_loop(win.mlx);
}
