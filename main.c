/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djanusz <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 15:07:01 by djanusz           #+#    #+#             */
/*   Updated: 2023/02/02 12:42:12 by djanusz          ###   ########.fr       */
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
	test((win.frame), 0, 0, 0x0000FF);
	test((win.frame), 50, 0, 0xFFFFFF);
	test((win.frame), 100, 0, 0xFF0000);
	mlx_put_image_to_window(win.mlx, win.ptr, win.frame.ptr, 0, 0);
	mlx_loop(win.mlx);
}
