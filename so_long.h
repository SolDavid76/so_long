/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djanusz <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 10:19:14 by djanusz           #+#    #+#             */
/*   Updated: 2023/01/24 13:55:17 by djanusz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# define SPAWN 0
# define EXIT 1
# define ITEM 2
# define BUFFER_SIZE 5
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdio.h>

typedef struct s_list
{
	char			*content;
	struct s_list	*next;
}					t_list;

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

#endif
