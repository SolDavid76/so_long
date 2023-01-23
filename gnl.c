/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djanusz <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 10:54:58 by djanusz           #+#    #+#             */
/*   Updated: 2023/01/23 13:49:36 by djanusz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static char	*ft_readstash(int fd, char *str)
{
	int		n;
	char	*tmp;

	n = 1;
	tmp = malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (!tmp)
		return (NULL);
	while (!ft_strchr(str, '\n') && n != 0)
	{
		n = read(fd, tmp, BUFFER_SIZE);
		if (n == -1)
			return (free(tmp), NULL);
		if (n == 0)
			return (free(tmp), str);
		tmp[n] = '\0';
		str = ft_strjoin(str, tmp);
	}
	return (free(tmp), str);
}

char	*get_next_line(int fd)
{
	static char	*stash;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	stash = ft_readstash(fd, stash);
	if (!stash)
		return (NULL);
	line = ft_get_line(stash);
	stash = ft_clean(stash);
	if (!line)
		return (free(stash), NULL);
	return (line);
}
