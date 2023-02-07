/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djanusz <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 10:19:14 by djanusz           #+#    #+#             */
/*   Updated: 2023/02/07 18:17:20 by djanusz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# define SPAWN 0
# define EXIT 1
# define ITEM 2
# define BUFFER_SIZE 5
# include "minilibx-linux/mlx.h"
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdio.h>

typedef struct s_list
{
	char			*content;
	struct s_list	*next;
}					t_list;

typedef struct s_img
{
	void	*ptr;
	char	*pxl;
	int		bpp;
	int		len;
	int		endian;
}			t_img;

typedef struct s_map
{
	char	**str;
	int		x_exit;
	int		y_exit;
	t_img	grass;
	t_img	wall;
	t_img	item;
	t_img	exit;
	t_img	player;
}			t_map;

typedef struct s_win
{
	void	*mlx;
	void	*ptr;
	int		width;
	int		height;
	t_img	frame;
	t_map	map;
}			t_win;

/* gnl */
char	*get_next_line(int fd);
int		ft_strlen(char *str);
int		ft_strchr(char *str, char c);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_get_line(char *str);
char	*ft_clean(char *str);

/* lst */
t_list	*ft_lstnew(char *content);
int		ft_lstsize(t_list *lst);
t_list	*ft_lstlast(t_list *lst);
void	ft_lstadd_back(t_list **lst, t_list *new);
void	ft_lstclear(t_list *lst);

/* mapping */
int		ft_maplen(char **map);
int		ft_mapchr(char **map, char c);
char	**create_map(int fd);
char	**dup_map(char **map);
void	free_map(char **map);

/* parsing */
char	**create_map(int fd);
int		valid_map_border(char **map);
int		valid_map_content(char **map);
int		path_finding(char **map);
char	**parsing(void);

/* graphics */
t_win	create_window(char **map);
t_img	ft_image_from_xpm(t_win win, char *path, int width, int height);
void	past_img_to_frame(t_img frame, t_img img, int x, int y);
void	rendering(t_win win, char **map);

/* event */
int		handle_input(int key, t_win *win);
int		move(t_win win, char **map, int key);

#endif
