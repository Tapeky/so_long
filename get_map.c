/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsadouk <tsadouk@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 16:25:40 by tsadouk           #+#    #+#             */
/*   Updated: 2023/12/07 13:47:55 by tsadouk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <mlx.h>
#include "so_long.h"
#include <fcntl.h>
#include "Get_Next_Line/get_next_line.h"
#include "Libft/libft.h"
#include <stdio.h>

int	get_height(void)
{
	int		fd;
	int		height;
	char	*line;

	height = 0;
	line = NULL;
	fd = open("map.txt", O_RDONLY);
	while (get_next_line(fd))
	{
		height++;
		free(line);
	}
	close(fd);
	return (height);
}

char	**get_map(void)
{
	int		fd;
	int		i;
	char	*line;
	char	**map;

	i = 0;
	fd = open("map.txt", O_RDONLY);
	line = NULL;
	map = malloc(sizeof(char *) * (get_height() + 1));
	if (!map)
		return (NULL);
	while ((line = get_next_line(fd)))
	{
		map[i] = ft_strdup(line);
		i++;
		free(line);
	}
	map[i] = NULL;
	close(fd);
	return (map);
}

int	main(void)
{
	char	**map;
	int		i;

	i = 0;
	printf("height = %d\n", get_height());
	map = get_map();
	while (map[i] != NULL)
	{
		printf("%s", map[i]);
		i++;
	}
	return (0);
}
