/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsadouk <tsadouk@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 16:25:40 by tsadouk           #+#    #+#             */
/*   Updated: 2024/01/16 15:12:31 by tsadouk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	get_height(char *path_to_map)
{
	int		fd;
	int		height;
	char	*line;

	height = 0;
	fd = open(path_to_map, O_RDONLY);
	line = get_next_line(fd);
	while (line)
	{
		free(line);
		line = get_next_line(fd);
		height++;
	}
	free(line);
	close(fd);
	return (height);
}

int	get_width(char *path_to_map)
{
	int		fd;
	int		width;
	char	*line;

	width = 0;
	line = NULL;
	fd = open(path_to_map, O_RDONLY);
	line = get_next_line(fd);
	width = ft_strlen(line);
	while (line)
	{
		free(line);
		line = get_next_line(fd);
	}
	free(line);
	close(fd);
	return (width - 1);
}

char	**get_map(char *path_to_map)
{
	int		fd;
	int		i;
	char	*line;
	char	**map;

	i = 0;
	fd = open(path_to_map, O_RDONLY);
	if (fd == -1)
		return (NULL);
	line = NULL;
	map = ft_calloc(sizeof(char *), (get_height(path_to_map) + 1));
	if (!map)
		return (NULL);
	line = get_next_line(fd);
	while (line)
	{
		map[i] = ft_strdup(line);
		i++;
		free(line);
		line = get_next_line(fd);
	}
	free(line);
	map[i] = NULL;
	close(fd);
	return (map);
}
