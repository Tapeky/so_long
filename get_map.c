/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsadouk <tsadouk@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 16:25:40 by tsadouk           #+#    #+#             */
/*   Updated: 2023/12/06 17:54:42 by tsadouk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <mlx.h>
#include "so_long.h"
#include "get_next_line.h"
#include "Libft/libft.h"
#include <stdio.h>

int	map_height()
{
	char *line;
	int	height;

	line = malloc(sizeof(char) * 1);
	if (!line)
		return (-1);
	height = 0;
	while (line = get_next_line(0))
	{
		height++;
		free(line);
	}
	free(line);
	return (height);
}

char **get_map(void)
{
	int height;
	int i;
	char *line;
	char **map;

	printf("get_map\n");
	height = map_height();
	map = (char **)malloc(sizeof(char *) * (height + 1));
	map[height + 1] = NULL;
	if (!map)
		return NULL;
	i = 0;
	while (line = get_next_line(0))
	{
		printf("line = %s\n", line);
		map[i] = ft_strdup(line);
		printf("map[%d] = %s\n", i, map[i]);
		free(line);
		i++;
	}
	return map;
}
int main (void)
{
	char **map = get_map();
	int height = map_height();
	int i = 0;
	
	if (!map)
	{
		printf("ERROR\n");
		return (-1);
	}
	while (map[i] != NULL)
	{
		printf("%s\n", map[i]);
		i++;
	}
	return (0);
}
