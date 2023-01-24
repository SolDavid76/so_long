/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl_aux.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djanusz <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 14:43:27 by djanusz           #+#    #+#             */
/*   Updated: 2023/01/24 14:01:36 by djanusz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
		i++;
	return (i);
}

int	ft_strchr(char *str, char c)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
	{
		if (str[i] == c)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*res;
	int		i;
	int		j;

	if (!s2)
		return (NULL);
	res = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!res)
		return (NULL);
	i = 0;
	j = 0;
	if (s1)
	{
		while (s1[i])
			res[j++] = s1[i++];
	}
	i = 0;
	while (s2[i])
		res[j++] = s2[i++];
	res[j] = '\0';
	if (s1)
		free(s1);
	return (res);
}

char	*ft_get_line(char *str)
{
	int		i;
	char	*res;

	i = 0;
	if (str[i] == '\0')
		return (NULL);
	while (str[i] && str[i] != '\n')
		i++;
	res = malloc(sizeof(char) * i + 1);
	if (!res)
		return (NULL);
	i = 0;
	while (str[i] && str[i] != '\n')
	{
		res[i] = str[i];
		i++;
	}
//	if (str[i] == '\n')
//	{
//		res[i] = str[i];
//		i++;
//	}
	res[i] = '\0';
	return (res);
}

char	*ft_clean(char *str)
{
	char	*res;
	int		i;
	int		j;

	i = 0;
	while (str[i] && str[i] != '\n')
		i++;
	if (str[i] == '\0')
		return (free(str), NULL);
	res = malloc(sizeof(char) * (ft_strlen(str) - i + 2));
	if (!res)
		return (NULL);
	i++;
	j = 0;
	while (str[i])
		res[j++] = str[i++];
	res[j] = '\0';
	return (free(str), res);
}
