/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphics.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djanusz <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 14:23:43 by djanusz           #+#    #+#             */
/*   Updated: 2023/02/02 12:45:41 by djanusz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_win	create_window(char **map)
{
	t_win	win;
	t_img	img;

	win.mlx = mlx_init();
	win.width = ft_strlen(map[0]) * 50;
	win.height = ft_maplen(map) * 50;
	win.ptr = mlx_new_window(win.mlx, win.width, win.height, "so_long");
	img.ptr = mlx_new_image(win.mlx, win.width, win.height);
	img.pixels = mlx_get_data_addr(img.ptr, &img.bpp, &img.len, &img.endian);
	win.frame = img;
	return (win);
}

t_img	image_from_xpm(t_win win, char *path, int width, int height)
{
	t_img	img;

	img.ptr = mlx_xpm_file_to_image(win.mlx, path, &width, &height);
	img.pixels = mlx_get_data_addr(img.ptr, &img.bpp, &img.len, &img.endian);
	return (img);
}

void	test(t_img img, int x, int y, int color)
{
	char	*pixel;
	int		i;
	int		j;

	i = 0;
	while (i < 50)
	{
		j = 0;
		while (j < 50)
		{
			pixel = img.pixels + ((i + y) * img.len + (j + x) * (img.bpp / 8));
			*(int *)pixel = color;
			j++;
		}
		i++;
	}
}
