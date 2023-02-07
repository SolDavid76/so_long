/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphics.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djanusz <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 14:23:43 by djanusz           #+#    #+#             */
/*   Updated: 2023/02/07 18:36:36 by djanusz          ###   ########.fr       */
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
	img.pxl = mlx_get_data_addr(img.ptr, &img.bpp, &img.len, &img.endian);
	win.frame = img;
	return (win);
}

t_img	ft_image_from_xpm(t_win win, char *path, int width, int height)
{
	t_img	img;

	img.ptr = mlx_xpm_file_to_image(win.mlx, path, &width, &height);
	img.pxl = mlx_get_data_addr(img.ptr, &img.bpp, &img.len, &img.endian);
	return (img);
}

void	past_img_to_frame(t_img frame, t_img img, int x, int y)
{
	char	*dst;
	char	*src;
	int		i;
	int		j;
	int		p;

	i = 0;
	while (i < 50)
	{
		j = 0;
		while (j < 50)
		{
			src = img.pxl + (i * img.len + j * (img.bpp / 8));
			dst = frame.pxl + ((i + y) * frame.len + (j + x) * (frame.bpp / 8));
			p = 0;
			while (p < 4)
			{
				dst[p] = src[p];
				p++;
			}
			j++;
		}
		i++;
	}
}

void	rendering(t_win win, char **map)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == '1')
				past_img_to_frame(win.frame, win.map.wall, j * 50, i * 50);
			else if (map[i][j] == 'C')
				past_img_to_frame(win.frame, win.map.item, j * 50, i * 50);
			else if (map[i][j] == 'E')
				past_img_to_frame(win.frame, win.map.exit, j * 50, i * 50);
			else if (map[i][j] == 'P')
				past_img_to_frame(win.frame, win.map.player, j * 50, i * 50);
			else
				past_img_to_frame(win.frame, win.map.grass, j * 50, i * 50);
			j++;
		}
	i++;
	}
	if (ft_mapchr(map, 'P') != win.map.y_exit || ft_strchr(map[ft_mapchr(map, 'P')], 'P') != win.map.x_exit)
		past_img_to_frame(win.frame, win.map.exit, win.map.x_exit * 50, win.map.y_exit * 50); // <- sa grand mew 
	mlx_put_image_to_window(win.mlx, win.ptr, win.frame.ptr, 0, 0);
}
